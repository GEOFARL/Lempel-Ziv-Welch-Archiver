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

  cout << mode << endl;
  cout << outputFilename << endl;
  return 0;
}