#include "TrieString.h"

TrieString::TrieString(const Trie& dict, const std::string word) {
  word_.push_back(dict.root());
  str_ = word;

  for (std::size_t i = 0; i < word.length(); ++i) {
    TrieNode* child = word_.back()->child(word[i]);

    if (child != NULL)
      word_.push_back(child);
    else
      break;
  }
}


std::string TrieString::str() const {
  return str_;
}


bool TrieString::is_subword() const {
  return str_.length() == word_.size() - 1;
}


bool TrieString::is_word() const {
  return is_subword() && word_.back()->is_final();
}


TrieString& TrieString::operator+=(char c) {
  str_ += c;

  TrieNode* child = word_.back()->child(c);
  if (child != NULL)
    word_.push_back(child);

  return *this;
}


TrieString TrieString::operator+(char c) const {
  TrieString new_word = *this;
  new_word += c;

  return new_word;
}
