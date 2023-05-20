#pragma once

#include <vector>
#include <string>
#include <fstream>

class Archiver
{
public:
  void compress(const std::vector<std::string> &, const std::string &);
};