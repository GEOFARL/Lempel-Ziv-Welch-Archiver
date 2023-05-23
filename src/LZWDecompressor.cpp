#include "LZWDecompressor.hpp"

LZWDecompressor::LZWDecompressor(std::ifstream &inputFile)
    : reader(inputFile)
{
}

void LZWDecompressor::decompressFile(const std::string &outputFile)
{
  std::ofstream outfile(outputFile, std::ios::binary);
  if (!outfile)
  {
    throw std::runtime_error("Failed to open the file.");
  }

  uint32_t previousIndex{IDictionary::EMPTY};
  uint32_t currentIndex{IDictionary::EMPTY};

  const std::vector<char> *string;

  while (true)
  {
    if (dictionary.isFull())
    {
      dictionary.reset();
      reader.resetBinaryWindowLength();
    }

    while (IBitStream::findNumOfRequiredBits(dictionary.getSize()) > reader.getBinaryWindowLength())
    {
      reader.increaseBinaryWindowLength();
    }

    // If the EOF was encountered
    if (!reader.read(currentIndex))
    {
      break;
    }

    // Check for invalid code
    if (currentIndex > dictionary.getSize())
    {
      throw std::runtime_error("Invalid compression code: " + std::to_string(currentIndex) + " " + std::to_string(dictionary.getSize()));
    }

    if (currentIndex == dictionary.getSize())
    {
      dictionary.addPair(previousIndex, dictionary.reconstructString(previousIndex)->front());
      string = dictionary.reconstructString(currentIndex);
    }
    else
    {
      string = dictionary.reconstructString(currentIndex);
      if (previousIndex != IDictionary::EMPTY)
      {
        dictionary.addPair(previousIndex, string->front());
      }
    }

    outfile.write(&string->front(), string->size());
    previousIndex = currentIndex;
  }
  outfile.close();
}