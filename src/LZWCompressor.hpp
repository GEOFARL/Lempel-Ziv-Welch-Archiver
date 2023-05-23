#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "EncoderDictionary.hpp"
#include "BitWriter.hpp"
#include "IBitStream.hpp"

class LZWCompressor
{
  EncoderDictionary dictionary;
  BitWriter writer;

public:
  LZWCompressor(std::ofstream &);
  void compressFile(const std::string &);
};