#include "EncoderDictionary.hpp"

EncoderDictionary::EncoderDictionary()
{
  setUpInitialTable();
  // It's needed to not reallocate memory many times
  vectorOfNodes.reserve(IDictionary::MAX_SIZE);
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
  // Fictional node to be in place of EOF
  vectorOfNodes.push_back(Node(0));
}

uint32_t EncoderDictionary::searchAndInsert(uint32_t index, char ch)
{
  if (index == IDictionary::EMPTY)
  {
    // need an initial table for O(1) lookup instead of searching in O(N)
    // through the vector of Nodes
    return searchInInitialTable(ch);
  }

  // Next index in the table
  const uint32_t nextIndex = vectorOfNodes.size();
  uint32_t cursor = vectorOfNodes[index].nextNode;

  if (cursor == IDictionary::EMPTY)
  {
    vectorOfNodes[index].nextNode = nextIndex;
  }
  else // Traversing binary tree
  {
    bool done = false;
    while (!done)
    {
      // Left tree
      if (ch < vectorOfNodes[cursor].currentChar)
      {
        // On the leaf
        if (vectorOfNodes[cursor].left == IDictionary::EMPTY)
        {
          vectorOfNodes[cursor].left = nextIndex;
          done = true;
        }
        // Moving on
        else
        {
          cursor = vectorOfNodes[cursor].left;
        }
      }
      // Right tree
      else if (ch > vectorOfNodes[cursor].currentChar)
      {
        // On the leaf
        if (vectorOfNodes[cursor].right == IDictionary::EMPTY)
        {
          vectorOfNodes[cursor].right = nextIndex;
          done = true;
        }
        // Moving on
        else
        {
          cursor = vectorOfNodes[cursor].right;
        }
      }
      // Match
      else
      {
        // Do not need to insert new value
        return cursor;
      }
    }
  }

  vectorOfNodes.push_back(Node(ch));

  // Nothing found, inserted only
  return IDictionary::EMPTY;
}

void EncoderDictionary::setUpInitialTable()
{
  uint32_t current{};
  for (int ch = -128; ch < 128; ++ch)
  {
    initialTable[static_cast<unsigned char>(ch)] = current++;
  }
}

uint32_t EncoderDictionary::searchInInitialTable(char ch) const
{
  return initialTable[static_cast<unsigned char>(ch)];
}

bool EncoderDictionary::isFull() const
{
  return getSize() == IDictionary::MAX_SIZE;
}

std::size_t EncoderDictionary::getSize() const
{
  return vectorOfNodes.size();
}
