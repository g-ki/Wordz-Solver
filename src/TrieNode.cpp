#include "TrieNode.h"

TrieNode::TrieNode() : value_('\0'), is_final_(false) {

}


TrieNode::TrieNode(char value, bool is_final) {
  value_ = value;
  is_final_ = is_final;
}


TrieNode::~TrieNode() {
  for (std::size_t i = 0; i < children_.size(); ++i)
    delete children_[i];
}


char TrieNode::value() const {
  return value_;
}


bool TrieNode::is_final() const {
  return is_final_;
}


TrieNode* TrieNode::child(char val) const {
  for (std::size_t i = 0; i < children_.size(); ++i)
    if (children_[i]->value() == val)
      return children_[i];

  return NULL;
}


std::size_t TrieNode::size() const {
  std::size_t size = children_.size();

  for (std::size_t i = 0; i < children_.size(); ++i)
    size += children_[i]->size();

  return size;
}


void TrieNode::insert(TrieNode* child) {
  children_.push_back(child);
}


void TrieNode::value(char val) {
  value_ = val;
}


void TrieNode::is_final(bool flag) {
  is_final_ = flag;
}
