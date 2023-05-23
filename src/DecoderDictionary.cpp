#include "DecoderDictionary.hpp"

const uint32_t IDictionary::MAX_SIZE;

DecoderDictionary::DecoderDictionary()
{
  // It's needed to not reallocate memory many times
  table.reserve(IDictionary::MAX_SIZE);
  reconstructedString.reserve(IDictionary::MAX_SIZE);
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

std::vector<char> *DecoderDictionary::reconstructString(uint32_t index)
{
  reconstructedString.clear();

  while (index != IDictionary::EMPTY)
  {
    // Add a char to a string
    reconstructedString.push_back(table[index].second);
    // Move further
    index = table[index].first;
  }

  // Reverse a string
  std::reverse(reconstructedString.begin(), reconstructedString.end());
  return &reconstructedString;
}
