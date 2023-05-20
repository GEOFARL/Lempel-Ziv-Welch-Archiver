#include <iostream>
#include <string>
#include <vector>

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
  return 0;
}