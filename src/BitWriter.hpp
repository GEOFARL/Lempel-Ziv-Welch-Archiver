#pragma once

#include "IBitStream.hpp"

class BitWriter : IBitStream
{
  std::ofstream &file;

public:
  BitWriter(std::ofstream &);

  virtual std::size_t getBinaryWindowLength() const override;
  virtual void resetBinaryWindowLength() override;
  virtual void increaseBinaryWindowLength() override;

  void write(uint32_t);

  ~BitWriter();
};