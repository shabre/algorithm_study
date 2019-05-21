//
//  main.cpp
//  acm11726
//
//  Created by Shabre on 2018. 10. 9..
//  Copyright © 2018년 Shabre. All rights reserved.
//

#include <iostream>
#include <cstring>
#define MAX 1001

using namespace std;

int tileCntArr[MAX];
int n;

void addTileCnt(int cur);

int main(int argc, const char * argv[]) {
    
    cin>>n;
    memset(tileCntArr, 0, MAX * sizeof(int));
    tileCntArr[1] = 1;
    tileCntArr[2] = 2;
    
    for(int i = 3; i<=n; i++) {
        addTileCnt(i);
    }
    cout<<tileCntArr[n];
    
    return 0;
}

void addTileCnt(int cur) {
    tileCntArr[cur] += (tileCntArr[cur-2] + tileCntArr[cur-1]) % 10007;
}
