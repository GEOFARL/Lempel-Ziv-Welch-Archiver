#include <iostream>
#include <string>
#include <vector>

#include "FileValidator.hpp"
#include "Archiver.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    cerr << "Usage: " << argv[0] << " [--compress | --decompress] <output_file> [<input_files>...] " << endl;
    return 1;
  }

  string mode = argv[1];
  string outputFilename = argv[2];
  vector<string> inputFiles;

  if (mode == "--compress")
  {
    if (argc < 4)
    {
      cerr << "Usage: " << argv[0] << " --compress <output_file> <input_files>..." << endl;
      return 1;
    }

    for (int i = 3; i < argc; ++i)
    {
      if (FileValidator::isValidInputFile(argv[i]))
      {
        inputFiles.push_back(argv[i]);
      }
      else
      {
        std::cerr << "Invalid input file: " << argv[i] << std::endl;
        return 1;
      }
    }
  }
  else if (mode != "--decompress")
  {
    cerr << "Invalid mode. Please specify either --compress or --decompress." << endl;
    return 1;
  }
  else if (argc != 3)
  {
    cerr << "Usage: " << argv[0] << " --decompress <archive_file>" << endl;
    return 1;
  }

  if (!FileValidator::isValidArchiveExtension(outputFilename))
  {
    cerr << "Invalid archive extension for the " << outputFilename << std::endl;
    cerr << "You should use " << FileValidator::validArchiveExt << std::endl;
    return 1;
  }

  try
  {
    Archiver archiver;
    if (mode == "--compress")
    {
      archiver.compress(inputFiles, outputFilename);
    }
    else
    {
      archiver.decompress(outputFilename);
    }
  }
  catch (const exception &e)
  {
    cerr << e.what() << endl;
  }
  return 0;
}