#ifndef wordz_trieString
#define wordz_trieString

#include<string>
#include "Trie.h"


class TrieString {
  std::vector<const TrieNode*> word_;
  std::string str_;

public:
  TrieString(const Trie& dict, std::string word = "");

  std::string str() const;
  bool is_subword() const;
  bool is_word() const;

  operator std::string() const { return str(); }

  TrieString& operator+=(char c);
  TrieString operator+(char c) const;
};

#endif
