//
//  Trie.h
//  wordzCrack
//
//  Created by Georgi Kiryakov on 3/26/15.
//  Copyright (c) 2015 Georgi Kiryakov. All rights reserved.
//

#ifndef __wordzCrack__Trie__
#define __wordzCrack__Trie__

#include"TrieNode.h"


class Trie {
    TrieNode *root;
public:
    
    Trie();
    ~Trie();
    
    void AddWord(string s);
    bool SearchWord(string s);
    /*
    TrieNode* SearchPath(char c);
    TrieNode* SearchPath(char c, TrieNode* node); */
    TrieNode* GetRoot() const { return root; }
    
    unsigned long Size() const { return root->Size(); }
    
};
#endif /* defined(__wordzCrack__Trie__) */
