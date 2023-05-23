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