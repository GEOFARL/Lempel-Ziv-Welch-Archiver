#include "BitReader.hpp"

BitReader::BitReader(const std::string &fileName)
    : IBitStream(9), file(fileName, std::ios::binary)
{
  if (!file)
  {
    // Failed to open the file
    throw std::runtime_error("Failed to open file: " + fileName);
  }
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

void BitReader::read(uint32_t)
{
}

BitReader::~BitReader()
{
  file.close();
}