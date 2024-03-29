#pragma once

#include "IDictionary.hpp"
#include <array>

class EncoderDictionary : IDictionary
{
  struct Node
  {
    uint32_t nextNode;
    char currentChar;
    uint32_t left;
    uint32_t right;

    explicit Node(char current)
        : nextNode{IDictionary::EMPTY},
          currentChar{current},
          left{IDictionary::EMPTY},
          right{IDictionary::EMPTY}
    {
    }
  };

  std::vector<Node> vectorOfNodes;
  std::array<uint32_t, 256> initialTable;

  void setUpInitialTable();

public:
  EncoderDictionary();
  virtual void reset() override;
  virtual bool isFull() const override;
  virtual std::size_t getSize() const override;

  uint32_t searchAndInsert(uint32_t, char);
  uint32_t searchInInitialTable(char) const;
};