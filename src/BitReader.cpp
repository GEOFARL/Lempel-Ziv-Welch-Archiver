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
}
void BitReader::resetBinaryWindowLength()
{
}
void BitReader::increaseBinaryWindowLength()
{
}

void BitReader::read(uint32_t)
{
}

BitReader::~BitReader()
{
}