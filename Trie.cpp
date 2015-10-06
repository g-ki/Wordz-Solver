//
//  Trie.cpp
//  wordzCrack
//
//  Created by Georgi Kiryakov on 3/26/15.
//  Copyright (c) 2015 Georgi Kiryakov. All rights reserved.
//

#include "Trie.h"
#include <iostream>
using namespace std;

Trie::Trie()
{
    root = new TrieNode(' ', false);
}

Trie::~Trie()
{
    delete root;
}

void Trie::AddWord(string s) {
    TrieNode* current = root;
    
    
    if(s.length() == 0)
    {
        current->Mark(); // recognize empty word
        return;
    }
    
    unsigned long len = s.length();
    for (int i=0; i<len-1; i++) {
        
        TrieNode *child = current->FindChild(s[i]);
        
        if(child != NULL)
        {
            current = child;
        }
        else {
            TrieNode* tmp = new TrieNode(s[i], false);
            tmp->Set(s[i]);
            current->AddChild(tmp);
            current = tmp;
        }
        
        if (s[i+1]=='/') {
            current->Mark();
            break;
        }
        
        if ( i == len - 2 )
            current->Mark();
    }
}

bool Trie::SearchWord(string s) {
    TrieNode* current = root;
    unsigned long len = s.length();
    
    for (int i=0; i<len; i++) {
        current = current->FindChild(s[i]);
        
        if(current == NULL)
            return false;
    }
    
    if(current->IsFinal())
        return true;
    
    return false;
}
/*
TrieNode* Trie::SearchPath(char c){
    
    TrieNode* node = root;
    
    node = node->FindChild(c);
    if(node == NULL)
        return NULL;
    
    return node;
}

TrieNode* Trie::SearchPath(char c, TrieNode* node){
    
    if(node == NULL)
        return NULL;
    
    node = node->FindChild(c);
    if(node == NULL)
        return NULL;
    
    
    return node;
} */
