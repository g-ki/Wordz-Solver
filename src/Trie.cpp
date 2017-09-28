#include "Trie.h"

Trie::Trie() {
  root_ = new TrieNode('\0', false);
}

Trie::~Trie() {
  delete root_;
}

void Trie::insert(std::string str) {
  TrieNode* current = root_;

  for (std::size_t i = 0; i < str.length(); ++i) {
    TrieNode* child = current->child(str[i]);

    if (child != NULL) {
      current = child;
    } else {
      TrieNode* tmp = new TrieNode(str[i], false);
      current->insert(tmp);
      current = tmp;
    }
  }

  current->is_final(true);
}


bool Trie::has(std::string str) const {
  TrieNode* current = root_;

  for (std::size_t i = 0; i < str.length(); ++i) {
    current = current->child(str[i]);
    if (current == NULL)
      return false;
  }

  if (current->is_final())
    return true;

  return false;
}

const TrieNode* Trie::root() const {
  return root_;
}

std::size_t Trie::size() const {
  return root_->size();
}
