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
  // Fictional node to be in place of EOF
  addPair(0, 0);
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

bool DecoderDictionary::isFull() const
{
  return getSize() == IDictionary::MAX_SIZE;
}

std::size_t DecoderDictionary::getSize() const
{
  return table.size();
}

void DecoderDictionary::addPair(uint32_t code, char ch)
{
  table.push_back({code, ch});
}
