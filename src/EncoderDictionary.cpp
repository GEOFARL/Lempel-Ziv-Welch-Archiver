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

uint32_t EncoderDictionary::searchAndInsert(uint32_t index, char ch)
{
  if (index == IDictionary::EMPTY)
  {
    // need an initial table for O(1) lookup instead of searching in O(N)
    // through the vector of Nodes
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