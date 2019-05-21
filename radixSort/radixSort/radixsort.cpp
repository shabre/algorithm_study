//
//  main.cpp
//  radixSort
//
//  Created by Shabre on 2017. 1. 28..
//  Copyright © 2017년 Shabre. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

void radixSort(int *ary, int size, int p){
    queue<int> bucket[10];
    int *temp=new int[size];
    int bucketList=0;
    int bucketNum=0;
    
    for(int i=0; i<size; i++){
        bucketNum=ary[i]/p;
        bucketNum%=10;
        bucket[bucketNum].push(ary[i]);
    }
    for(int i=0; i<size; i++){
        while(bucket[bucketList].empty())
            bucketList++;
        temp[i]=bucket[bucketList].front();
        bucket[bucketList].pop();
    }
    memcpy(ary,temp,sizeof(int)*size);
    delete []temp;
}

int main(int argc, const char * argv[]) {
    int inputNum;
    int maxNum=0;
    int point=1;
    cin>>inputNum;
    int *inArr=new int[inputNum];
    for(int i=0; i<inputNum; i++){
        cin>>inArr[i];
        if(maxNum<inArr[i])
            maxNum=inArr[i];
    }
    
    do{
        radixSort(inArr, inputNum, point);
        point*=10;
    }while((maxNum/point)!=0);
  
    
    for(int i=0; i<inputNum; i++){
        cout<<inArr[i]<<endl;
    }
}
