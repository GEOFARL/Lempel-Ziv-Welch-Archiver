#pragma once

#include <vector>
#include <cstdint>
#include <string>
#include <fstream>
#include <iostream>

#include "LZWCompressor.hpp"
#include "LZWDecompressor.hpp"

class Archiver
{
public:
  void compress(const std::vector<std::string> &, const std::string &);
  void decompress(const std::string &);
};