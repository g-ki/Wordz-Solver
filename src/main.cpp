#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>

#include "Trie.h"
#include "TrieString.h"

Trie load_dict(const char* file_path);

std::vector<std::string> wordz_at(const std::string& grid, const TrieString& word, std::size_t x, std::size_t y);

std::vector<std::string> wordz(const std::string& grid, const Trie& dict);

int main(int argc, char const *argv[])
{
  Trie dict = load_dict(argv[1]);

  std::string grid = argv[2];

  std::vector<std::string> results = wordz(grid, dict);

  for (int i = 0; i < results.size(); ++i)
    std::cout << i << ": "<< results[i] << std::endl;

  return 0;
}




Trie load_dict(const char* file_path) {
  Trie dict;
  std::ifstream file(file_path);
  std::string word;

  while(file >> word)
    dict.insert(word);

  return dict;
}


bool cmp_str_len (std::string a, std::string b) { return a.length() > b.length(); }

std::vector<std::string> wordz(const std::string& grid, const Trie& dict) {
  const std::size_t grid_size = sqrt(grid.length());
  std::vector<std::string> results, tmp;
  TrieString empty_str(dict);

  for (int i = 0; i < grid_size; ++i)
    for(int j = 0; j < grid_size; ++j) {
      tmp = wordz_at(grid, empty_str, i, j);
      results.insert(results.end(), tmp.begin(), tmp.end());
    }

  std::sort (results.begin(), results.end(), cmp_str_len);
  return results;
}


std::vector<std::string> wordz_at(const std::string& grid, const TrieString& t_str, std::size_t x, std::size_t y) {
  const std::size_t grid_size = sqrt(grid.length());
  const std::size_t index = grid_size * x + y;
  std::vector<std::string> v_words;

  bool is_index_valid = x < grid_size && y < grid_size;

  if (!is_index_valid || grid[index] == '\27') return v_words;

  TrieString next_t_str = t_str + grid[index];
  if (!next_t_str.is_subword()) return v_words;


  if (next_t_str.is_word())
    v_words.push_back(next_t_str);

  std::string next_grid = grid;
  next_grid[index] = '\27';
  std::vector<std::string> next_words;

  for (int i = -1; i <= 1; ++i)
    for(int j = -1; j <= 1; ++j) {
      if (i == 0 && j == 0) continue;
      next_words = wordz_at(next_grid, next_t_str, x + i, y + j);
      v_words.insert(v_words.end(), next_words.begin(), next_words.end());
    }

  return v_words;
}


