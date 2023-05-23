#pragma once

#include "IDictionary.hpp"
#include <utility>

class DecoderDictionary : IDictionary
{
  std::vector<std::pair<uint32_t, char>> table;

public:
  DecoderDictionary();
  virtual void reset() override;
};