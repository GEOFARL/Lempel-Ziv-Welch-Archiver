#pragma once

#include "IBitStream.hpp"
#include <array>

class BitReader : IBitStream
{
  std::ifstream file;
  std::array<int, 9> bitMasks;

public:
  BitReader(const std::string &);

  virtual std::size_t getBinaryWindowLength() const override;
  virtual void resetBinaryWindowLength() override;
  virtual void increaseBinaryWindowLength() override;

  bool read(uint32_t &);

  ~BitReader();
};