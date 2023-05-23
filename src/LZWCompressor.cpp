#include "LZWCompressor.hpp"

void LZWCompressor::compressFile(const std::string &inputFile, std::ofstream &outputFile)
{
  std::ifstream infile(inputFile, std::ios::binary);
  if (!infile)
  {
    throw std::runtime_error("Failed to open the file.");
  }

  BitWriter writer{outputFile};
  char ch;
  uint32_t currentIndex{IDictionary::EMPTY};

  while (infile.get(ch))
  {
    if (dictionary.isFull())
    {
      dictionary.reset();
    }

    const uint32_t previousIndex{currentIndex};

    currentIndex = dictionary.searchAndInsert(previousIndex, ch);
    if (currentIndex == IDictionary::EMPTY)
    {
      // writing previous index ...

      currentIndex = dictionary.searchInInitialTable(ch);
    }
  }

  if (currentIndex != IDictionary::EMPTY)
  {
    // writing what's left
  }

  infile.close();
}