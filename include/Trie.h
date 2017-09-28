#ifndef wordz_trie
#define wordz_trie

#include <string>
#include "TrieNode.h"

class Trie {
  TrieNode* root_;

public:
  Trie();
  ~Trie();


  void insert(std::string str);
  bool has(std::string std) const;


  const TrieNode* root() const;
  std::size_t size() const;
};

#endif
