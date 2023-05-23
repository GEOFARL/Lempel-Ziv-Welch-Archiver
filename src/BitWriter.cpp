#include "BitWriter.hpp"

BitWriter::BitWriter(const std::string &fileName)
    : IBitStream(9), file(fileName, std::ios::binary)
{
}

std::size_t BitWriter::getBinaryWindowLength() const
{
}
void BitWriter::resetBinaryWindowLength()
{
}
void BitWriter::increaseBinaryWindowLength()
{
}