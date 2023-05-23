#include "LZWCompressor.hpp"

void LZWCompressor::compressFile(const std::string &inputFile, std::ofstream &outputFile)
{
  std::ifstream infile(inputFile, std::ios::binary);

  if (!infile)
  {
    throw std::runtime_error("Failed to open the file.");
  }
}