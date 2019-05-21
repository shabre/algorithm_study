//
//  main.cpp
//  acm1181
//
//  Created by Shabre on 2018. 11. 11..
//  Copyright © 2018년 Shabre. All rights reserved.
//

#include <iostream>
using namespace std;

int alphabetCnt;

int getWordLevel (string word) {
    string::iterator it;
    for(it = word.end()-1; it != word.begin() ; --it) {
        cout<<(*it);
    }
    return 1;
}

int main(int argc, const char * argv[]) {

    alphabetCnt = 'z' - 'a' + 1;
    
    int count = 0;
    cin>>count;
    
    for (int i = 0; i<count; i++) {
        string word;
        cin>>word;
        getWordLevel(word);
    }
    
    return 0;
}

