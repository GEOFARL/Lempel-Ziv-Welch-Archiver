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

  virtual ~IBitStream() = default;

  static const uint32_t MY_EOF = 256;

  static std::size_t findNumOfRequiredBits(unsigned long int code)
  {
    std::size_t number{1};

    // shifting a bite at a time
    while ((code >>= 1) != 0)
    {
      number += 1;
    }

    return number;
  }
};