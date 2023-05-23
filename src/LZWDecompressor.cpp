#include "LZWDecompressor.hpp"

void LZWDecompressor::decompressFile(const std::string &outputFile, std::ifstream &inputFile)
{
  std::ofstream outfile(outputFile, std::ios::binary);
  if (!outfile)
  {
    throw std::runtime_error("Failed to open the file.");
  }

  BitReader reader{inputFile};
}