#include "DecoderDictionary.hpp"

DecoderDictionary::DecoderDictionary()
{
  // It's needed to not reallocate memory many times
  table.reserve(IDictionary::MAX_SIZE);
  reset();
}

void DecoderDictionary::reset()
{
  table.clear();
  // Setting initial table of ASCII characters
  for (int ch = -128; ch < 128; ++ch)
  {
    table.push_back({IDictionary::MAX_SIZE, static_cast<char>(ch)});
  }
}
