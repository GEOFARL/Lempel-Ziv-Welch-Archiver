#pragma once

#include <iostream>
#include <fstream>
#include <string>

class IBitStream
{
protected:
  struct ByteBuffer
  {
    std::size_t numOfBitsInUse;
    unsigned char data;

    ByteBuffer() : numOfBitsInUse{0}, data{0} {}
  };

  std::size_t binaryWindowLength;
  ByteBuffer bitCache;

public:
  IBitStream(std::size_t winLen) : binaryWindowLength(winLen) {}
  virtual std::size_t getBinaryWindowLength() const = 0;
  virtual void resetBinaryWindowLength() = 0;
  virtual void increaseBinaryWindowLength() = 0;
};