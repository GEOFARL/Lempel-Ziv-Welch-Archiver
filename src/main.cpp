#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    std::cerr << "Usage: " << argv[0] << " [--compress | --decompress] <output_file> [<input_files>...] " << std::endl;
    return 1;
  }
  return 0;
}