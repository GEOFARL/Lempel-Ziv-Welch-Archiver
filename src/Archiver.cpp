#include "Archiver.hpp"

void Archiver::compress(const std::vector<std::string> &inputFiles, const std::string &outputFilename)
{
  std::ofstream outFile(outputFilename, std::ios::binary);

  // Write the number of input files to the output file
  unsigned int numFiles = inputFiles.size();
  outFile.write(reinterpret_cast<const char *>(&numFiles), sizeof(numFiles));
}