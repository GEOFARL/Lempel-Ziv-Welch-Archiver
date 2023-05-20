#include "Archiver.hpp"

void Archiver::compress(const std::vector<std::string> &inputFiles, const std::string &outputFilename)
{
  std::ofstream outFile(outputFilename, std::ios::binary);

  // Write the number of input files to the output file
  unsigned int numFiles = inputFiles.size();
  outFile.write(reinterpret_cast<const char *>(&numFiles), sizeof(numFiles));

  for (const std::string &inputFile : inputFiles)
  {
    // Write the length of the file name and the file name itself
    // to the output file
    unsigned int filenameLength = inputFile.size();
    outFile.write(reinterpret_cast<const char *>(&filenameLength), sizeof(filenameLength));
    outFile.write(inputFile.c_str(), filenameLength);
  }

  outFile.close();
}

void Archiver::decompress(const std::string &inputFilename)
{
  std::ifstream infile(inputFilename, std::ios::binary);

  // Read the number of input files from the input file
  unsigned int numFiles;
  infile.read(reinterpret_cast<char *>(&numFiles), sizeof(numFiles));
  std::cout << "Read: " << numFiles << std::endl;

  for (unsigned int i = 0; i < numFiles; ++i)
  {
    // Read the length of the file name and the file name itself from
    // the input file
    unsigned int filenameLength;
    infile.read(reinterpret_cast<char *>(&filenameLength), sizeof(filenameLength));
    std::string filename(filenameLength, ' ');
    infile.read(&filename[0], filenameLength);
    std::cout << "Filename " << i + 1 << " : " << filename << std::endl;
  }
  infile.close();
}