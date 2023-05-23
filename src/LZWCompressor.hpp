#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class LZWCompressor
{
public:
  void compressFile(const std::string &, std::ofstream &);
};