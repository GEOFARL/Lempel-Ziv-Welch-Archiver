#pragma once

#include <iostream>
#include <string>
#include <fstream>

class LZ78Compressor
{
public:
  void compressFile(const std::string &infile, std::ofstream &outfile);
};