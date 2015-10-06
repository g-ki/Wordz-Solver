//
//  WordzTrie.cpp
//  wordzCrack
//
//  Created by Georgi Kiryakov on 3/28/15.
//  Copyright (c) 2015 Georgi Kiryakov. All rights reserved.
//

#include "Wordz.h"


Wordz::Wordz()
{
    tmpWord = "";
    tmpNode = NULL;
    loops = 0;
}


int Wordz::__isWord(string c)
{
    if(tmpNode == NULL)
    {
        nodeStack.push(tmpNode); // push NULL
        tmpNode = trie.GetRoot();
    }
    
    nodeStack.push(tmpNode);
    
    tmpNode = tmpNode->FindChild(c[0]);
    if(tmpNode != NULL)
        tmpNode = tmpNode->FindChild(c[1]);
    
    if(tmpNode == NULL)
    {
        tmpNode = nodeStack.top();
        nodeStack.pop();
        // move step back and
        return 0;
        // return 0, there is no possible moves with this letter
    }
    else if(tmpNode->IsFinal())
        return 1; // return 1, word is found
    else
        return -1; // return -1, there are possbile moves
}


void Wordz::__SearchWords(int x, int y)
{
    loops++;
    if(x < 0 || y < 0 || x >= GRID_SIZE || y >= GRID_SIZE || wordz[x][y]== "XX")
        return;
    
    int isWord = __isWord(wordz[x][y]);
    
    if(isWord == 0)
        return;
    
    tmpWord += wordz[x][y];
    
    if (isWord == 1)
        found.push_back(tmpWord);
    
    string tmp = wordz[x][y];
    wordz[x][y] = "XX";
    
    __SearchWords(x-1, y-1);
    __SearchWords(x-1, y);
    __SearchWords(x-1, y+1);
    
    __SearchWords(x, y-1);
    //__SearchWords(x, y);
    __SearchWords(x, y+1);
    
    __SearchWords(x+1, y-1);
    __SearchWords(x+1, y);
    __SearchWords(x+1, y+1);
    
    //step back ...
    wordz[x][y] = tmp;
    tmpWord = tmpWord.substr(0, tmpWord.size() - 2); // remove last letter
    
    tmpNode = nodeStack.top();
    nodeStack.pop();
    
    return;
}

void Wordz::__SearchWords2(int x, int y, string word) {
    
    loops++;
    if(x < 0 || y < 0 || x >= GRID_SIZE || y >= GRID_SIZE || wordz[x][y] == "X")
        return;
    
    
    if(trie.SearchWord(word))
        found.push_back(word);
    
    string t = wordz[x][y];
    wordz[x][y] = "X";
    
    __SearchWords2(x-1, y-1, word+t);
    __SearchWords2(x-1, y, word+t);
    __SearchWords2(x-1, y+1, word+t);
    
    __SearchWords2(x, y-1, word+t);
    __SearchWords2(x, y+1, word+t);
    
    __SearchWords2(x+1, y-1, word+t);
    __SearchWords2(x+1, y, word+t);
    __SearchWords2(x+1, y+1, word+t);
    
    wordz[x][y] = t;
    return;
}

void Wordz::Run()
{
    found.clear();
    
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            __SearchWords(i,j);
}

void Wordz::SetDictionary(const char* filePath)
{
    ifstream file(filePath);
    string str;
    
    while (std::getline(file, str))
    {
        if (str.length() >= 8)
           trie.AddWord(str);
    }
    file.close();
}

bool Wordz::SetGrid(string s)
{
    if(s.length() < GRID_SIZE*2)
    {
        std::cout<<"\nError!!! GRID_SIZE\n";
        return false;
    }
    int k = 0;
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
        {
            wordz[i][j] = s[k];
            wordz[i][j] += s[k+1];
            k+=2;
        }
    
    return true;
}

bool Wordz::__SortResults(string a, string b) {
    
    if(a.length() == b.length())
        return a<b;
    
    return a.length()>b.length();
}

vector<string> Wordz::Results()
{
    set<string> s( found.begin(), found.end() );
    found.assign( s.begin(), s.end() );
    sort(found.begin(), found.end(), __SortResults);
    return found;
}

