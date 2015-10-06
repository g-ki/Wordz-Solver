//
//  WordzTrie.h
//  wordzCrack
//
//  Created by Georgi Kiryakov on 3/28/15.
//  Copyright (c) 2015 Georgi Kiryakov. All rights reserved.
//

#ifndef __wordzCrack__WordzTrie__
#define __wordzCrack__WordzTrie__

#include "Trie.h"
#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>

#define GRID_SIZE 5

class Wordz{
    
    Trie trie;
    
    string wordz[GRID_SIZE][GRID_SIZE];
    vector<string> found;
    map<string, set<int>> foundMap;
    
    string tmpWord;
    TrieNode* tmpNode;
    stack<TrieNode *> nodeStack;
    
    int __isWord(string);
    void __SearchWords(int, int);
    void __SearchWords2(int, int, string word="");
    static bool __SortResults(string, string);
    
    size_t loops;
    
public:
    
    Wordz();
    
    void Run();
    
    void SetDictionary(const char*);
    bool SetGrid(string);
    
    Trie GetTrie() const { return trie; }
    vector<string> Results();
    
    size_t getLoops() const { return loops;}
    
    //void BuildMap();
    
};

#endif /* defined(__wordzCrack__WordzTrie__) */
