#pragma once

#include "IDictionary.hpp"
#include <utility>

class DecoderDictionary : IDictionary
{
  std::vector<std::pair<uint32_t, char>> table;
  std::vector<char> reconstructedString;

public:
  DecoderDictionary();
  virtual void reset() override;
  virtual bool isFull() const override;
  virtual std::size_t getSize() const override;

  std::vector<char> *reconstructString(uint32_t);
};