#include "Archiver.hpp"

void Archiver::compress(const std::vector<std::string> &inputFiles, const std::string &outputFilename)
{
  std::ofstream outFile(outputFilename, std::ios::binary);

  if (!outFile)
  {
    // Failed to open the file
    throw std::runtime_error("Failed to open file: " + outputFilename);
  }

  LZWCompressor compressor{outFile};

  // Write the number of input files to the output file
  uint8_t numFiles = inputFiles.size();
  outFile.write(reinterpret_cast<const char *>(&numFiles), sizeof(numFiles));

  for (const std::string &inputFile : inputFiles)
  {
    // Write the length of the file name and the file name itself
    // to the output file
    uint8_t filenameLength = inputFile.size();
    outFile.write(reinterpret_cast<const char *>(&filenameLength), sizeof(filenameLength));
    outFile.write(inputFile.c_str(), filenameLength);
  }

  for (const std::string &inputFile : inputFiles)
  {
    std::cout << "Compressing file " << inputFile << "... ";
    compressor.compressFile(inputFile);
    std::cout << "Done." << std::endl;
  }

  std::cout << "Result written to " << outputFilename << std::endl;

  outFile.close();
}

void Archiver::decompress(const std::string &inputFilename)
{
  std::ifstream infile(inputFilename, std::ios::binary);

  if (!infile)
  {
    // Failed to open the file
    throw std::runtime_error("Failed to open file: " + inputFilename);
  }

  LZWDecompressor decompressor{infile};

  // Read the number of input files from the input file
  uint8_t numFiles;
  infile.read(reinterpret_cast<char *>(&numFiles), sizeof(numFiles));

  std::vector<std::string> compressedFiles;
  for (uint8_t i = 0; i < numFiles; ++i)
  {
    // Read the length of the file name and the file name itself from
    // the input file
    uint8_t filenameLength;
    infile.read(reinterpret_cast<char *>(&filenameLength), sizeof(filenameLength));
    std::string filename(filenameLength, ' ');
    infile.read(&filename[0], filenameLength);
    compressedFiles.push_back(filename);
  }

  for (auto file : compressedFiles)
  {
    std::cout << "Getting out file " << file << "... ";
    decompressor.decompressFile("new_" + file);
    std::cout << "Done." << std::endl;
  }
  std::cout << compressedFiles.size() << " files written." << std::endl;
  infile.close();
}