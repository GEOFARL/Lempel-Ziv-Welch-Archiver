#include "BitWriter.hpp"

BitWriter::BitWriter(const std::string &fileName)
    : IBitStream(9), file(fileName, std::ios::binary)
{
  if (!file)
  {
    // Failed to open the file
    throw std::runtime_error("Failed to open file: " + fileName);
  }
}

std::size_t BitWriter::getBinaryWindowLength() const
{
  return binaryWindowLength;
}

void BitWriter::resetBinaryWindowLength()
{
  binaryWindowLength = 9;
}

void BitWriter::increaseBinaryWindowLength()
{
  binaryWindowLength += 1;
}

BitWriter::~BitWriter()
{
  // Write what's left
  if (bitCache.numOfBitsInUse != 0)
  {
    file.put(static_cast<char>(bitCache.data));
  }

  file.close();
}

void BitWriter::write(uint32_t code)
{
  // How many bits to write
  std::size_t leftBits{binaryWindowLength};

  // Handle bits left from the previous writing
  if (bitCache.numOfBitsInUse != 0)
  {
    // Adding as many bits as possible to the remaining byte
    bitCache.data |= code << bitCache.numOfBitsInUse;

    // Writing a complete byte to the file
    file.put(static_cast<char>(bitCache.data));

    // Removing bits that were already written
    code >>= 8 - bitCache.numOfBitsInUse;

    // Decreasing the number of the remaining bits
    leftBits -= 8 - bitCache.numOfBitsInUse;

    // Reseting a buffer
    bitCache.numOfBitsInUse = 0;
    bitCache.data = 0;
  }

  // Write rest of the bits
  while (leftBits != 0)
  {
    // More than a whole byte left
    if (leftBits >= 8)
    {
      file.put(static_cast<char>(code));
      code >>= 8;
      leftBits -= 8;
    }
    else // Cache left bits
    {
      bitCache.numOfBitsInUse = leftBits;
      bitCache.data = code;
      break;
    }
  }
}