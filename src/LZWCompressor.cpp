#include "LZWCompressor.hpp"

LZWCompressor::LZWCompressor(std::ofstream &outfile) : writer(outfile) {}

void LZWCompressor::compressFile(const std::string &inputFile)
{
  std::ifstream infile(inputFile, std::ios::binary);
  if (!infile)
  {
    throw std::runtime_error("Failed to open the file.");
  }

  char ch;
  uint32_t currentIndex{IDictionary::EMPTY};
  bool resetBitWindowLength{false};

  while (infile.get(ch))
  {
    if (dictionary.isFull())
    {
      dictionary.reset();
      resetBitWindowLength = true;
    }

    const uint32_t previousIndex{currentIndex};

    currentIndex = dictionary.searchAndInsert(previousIndex, ch);
    if (currentIndex == IDictionary::EMPTY)
    {
      // writing previous index ...
      writer.write(previousIndex);
      currentIndex = dictionary.searchInInitialTable(ch);

      while (IBitStream::findNumOfRequiredBits(dictionary.getSize() - 1) > writer.getBinaryWindowLength())
      {
        writer.increaseBinaryWindowLength();
      }
    }

    if (resetBitWindowLength)
    {
      writer.resetBinaryWindowLength();
      resetBitWindowLength = false;
    }
  }

  if (currentIndex != IDictionary::EMPTY)
  {
    // writing what's left
    writer.write(currentIndex);
  }

  writer.writeEOF();

  infile.close();
}