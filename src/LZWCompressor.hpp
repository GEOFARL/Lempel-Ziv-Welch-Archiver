#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "EncoderDictionary.hpp"
#include "BitWriter.hpp"

class LZWCompressor
{
  EncoderDictionary dictionary;

public:
  void compressFile(const std::string &, std::ofstream &);
};