#pragma once

#include "IDictionary.hpp"

class EncoderDictionary : IDictionary
{
  struct Node
  {
    uint32_t previousChar;
    char currentChar;
    uint32_t left;
    uint32_t right;

    explicit Node(char current)
        : previousChar{IDictionary::NULL},
          currentChar{current},
          left{IDictionary::NULL},
          right{IDictionary::NULL}
    {
    }
  };

public:
  EncoderDictionary();
  virtual void reset() override;
};