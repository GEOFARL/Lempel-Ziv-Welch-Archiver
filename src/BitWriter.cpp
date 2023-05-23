#include "BitWriter.hpp"

BitWriter::BitWriter(const std::string &fileName)
    : IBitStream(9), file(fileName, std::ios::binary)
{
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