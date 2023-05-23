#include "BitReader.hpp"

BitReader::BitReader(std::ifstream &file)
    : IBitStream(9),
      file{file},
      bitMasks{0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF},
      foundEOF{false}
{
}

std::size_t BitReader::getBinaryWindowLength() const
{
  return binaryWindowLength;
}

void BitReader::resetBinaryWindowLength()
{
  binaryWindowLength = 9;
}

void BitReader::increaseBinaryWindowLength()
{
  binaryWindowLength += 1;
}

bool BitReader::read(uint32_t &code)
{
  std::size_t leftBits{binaryWindowLength};
  std::size_t offset(bitCache.numOfBitsInUse);

  unsigned char charRead;

  // Write out leftovers from the buffer
  code = bitCache.data;
  leftBits -= bitCache.numOfBitsInUse;
  bitCache.numOfBitsInUse = 0;
  bitCache.data = 0;

  // Reading what's left to read
  while (leftBits != 0 && file.get(reinterpret_cast<char &>(charRead)))
  {
    // More than a byte left
    if (leftBits >= 8)
    {
      // Add a new byte to our code, taking into account bits
      // that were already added
      code |= static_cast<uint32_t>(charRead) << offset;
      offset += 8;
      leftBits -= 8;
    }
    else
    {
      // Using a bit mask to add only bits that's left and no more
      code |= static_cast<uint32_t>(charRead & bitMasks[leftBits]) << offset;
      bitCache.numOfBitsInUse = 8 - leftBits;
      bitCache.data = charRead >> leftBits;
      break;
    }
  }

  // Ending the reading process
  if (code == IBitStream::MY_EOF)
  {
    foundEOF = true;
    bitCache.numOfBitsInUse = 0;
    bitCache.data = 0;
    return false;
  }

  return true;
}

BitReader::~BitReader()
{
}