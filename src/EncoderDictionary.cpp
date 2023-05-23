#include "EncoderDictionary.hpp"

EncoderDictionary::EncoderDictionary()
{
  reset();
}

void EncoderDictionary::reset()
{
  vectorOfNodes.clear();
  // Setting initial table of ASCII characters
  for (int ch = -128; ch < 128; ++ch)
  {
    vectorOfNodes.push_back(Node(ch));
  }
}