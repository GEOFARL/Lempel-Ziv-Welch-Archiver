#pragma once

#include <cstdint>
#include <vector>

class IDictionary
{
protected:
  // 512 KB
  static const uint32_t MAX_SIZE = 512 * 1024;
  static const uint32_t EMPTY = MAX_SIZE;

  virtual void reset() = 0;
  virtual bool isFull() const = 0;
  virtual ~IDictionary() = default;
};