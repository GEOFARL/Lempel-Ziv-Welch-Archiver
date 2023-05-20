#include "Archiver.hpp"

void Archiver::compress(const std::vector<std::string> &inputFiles, const std::string &outputFilename)
{
  std::ofstream outFile(outputFilename, std::ios::binary);

  // Write the number of input files to the output file
  unsigned int numFiles = inputFiles.size();
  outFile.write(reinterpret_cast<const char *>(&numFiles), sizeof(numFiles));
  outFile.close();
}

void Archiver::decompress(const std::string &inputFilename)
{
  std::ifstream infile(inputFilename, std::ios::binary);

  // Read the number of input files from the input file
  unsigned int numFiles;
  infile.read(reinterpret_cast<char *>(&numFiles), sizeof(numFiles));
  std::cout << "Read: " << numFiles << std::endl;
  infile.close();
}