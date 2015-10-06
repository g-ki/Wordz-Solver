//
//  TrieNode.cpp
//  wordzCrack
//
//  Created by Georgi Kiryakov on 3/26/15.
//  Copyright (c) 2015 Georgi Kiryakov. All rights reserved.
//

#include "TrieNode.h"

TrieNode::TrieNode() : value('\0'), isFinal(false) {
    
}

TrieNode::TrieNode(char val, bool flag) : value(val), isFinal(flag) {

}

TrieNode::~TrieNode() {
    for (int i=0; i<childern.size(); i++)
        delete childern[i];
}

unsigned long TrieNode::Size(){
    
    unsigned long size = childern.size();
    
    for (int i=0; i<childern.size(); i++) {
        size += childern.at(i)->Size();
    }
    
    return size;
}

TrieNode* TrieNode::FindChild(char key) const {
    
    TrieNode *tmp;
    for (int i=0; i<childern.size(); i++) {
        tmp = childern.at(i);
        
        if(tmp->GetContent() == key)
            return tmp;
    }
    
    return NULL;
}