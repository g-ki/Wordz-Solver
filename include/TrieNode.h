#ifndef wordz__trieNode
#define wordz__trieNode

#include <vector>

class TrieNode {
  char value_;
  bool is_final_;
  std::vector<TrieNode*> children_;

public:
  TrieNode();
  TrieNode(char val, bool isFinal);
  ~TrieNode();


  char value() const;
  bool is_final() const;
  TrieNode* child(char key) const;
  std::size_t size() const;


  void insert(TrieNode* child);
  void value(char val);
  void is_final(bool flag);
};

#endif
