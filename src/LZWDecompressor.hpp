#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "DecoderDictionary.hpp"
#include "BitReader.hpp"
#include "IBitStream.hpp"

class LZWDecompressor
{
  DecoderDictionary dictionary;

public:
  void decompressFile(const std::string &, std::ifstream &);
};