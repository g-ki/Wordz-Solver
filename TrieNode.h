//
//  TrieNode.h
//  wordzCrack
//
//  Created by Georgi Kiryakov on 3/26/15.
//  Copyright (c) 2015 Georgi Kiryakov. All rights reserved.
//

#ifndef __wordzCrack__TrieNode__
#define __wordzCrack__TrieNode__

#include <vector>
#include <string>
using namespace std;

class TrieNode {
    
    char value;
    bool isFinal;
    std::vector<TrieNode*> childern;
    
public:
    
    TrieNode();
    TrieNode(char val, bool flag);
    ~TrieNode();
    
    char GetContent() const { return value; }
    bool IsFinal() const { return isFinal; }
    TrieNode* FindChild(char key) const;
    
    void AddChild(TrieNode* child) { childern.push_back(child); }
    void Mark() { isFinal = true; }
    void Set(char val) { value = val; }
    
    unsigned long Size();
    
};




#endif /* defined(__wordzCrack__TrieNode__) */
