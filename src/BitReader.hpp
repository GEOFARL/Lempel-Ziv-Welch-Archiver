#pragma once

#include "IBitStream.hpp"

class BitReader : IBitStream
{
  std::ifstream file;

public:
  BitReader(const std::string &);

  virtual std::size_t getBinaryWindowLength() const override;
  virtual void resetBinaryWindowLength() override;
  virtual void increaseBinaryWindowLength() override;

  void read(uint32_t);

  ~BitReader();
};