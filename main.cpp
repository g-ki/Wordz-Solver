//
//  main.cpp
//  wordzCrack
//
//  Created by Georgi Kiryakov on 3/26/15.
//  Copyright (c) 2015 Georgi Kiryakov. All rights reserved.
//

#include <iostream>
#include "Wordz.h"

void ClearScreen()
{
    cout << string( 100, '\n' );
}

int main(int argc, const char * argv[]) {
    
    clock_t begin_time = clock();
    // do something
    
    Wordz wordz;
    
    wordz.SetDictionary("bg_BG.dic"); // bg_BG.dic
    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
  
    string input;
    
    /*
     ияжкрепдотсгасиу
     вшргкаенвзблелми
     лтзепнеиясончбпр
    */
    
    getline(cin, input);
    
    if(!wordz.SetGrid(input))
        return -1;
    
    begin_time = clock();
    wordz.Run();
    
    vector<string> found = wordz.Results();
    
    for (int i=0; i<found.size(); i++) {
        cout<<found[i]<<endl;
    }

    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
        
    return 0;
}
