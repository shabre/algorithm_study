//
//  main.cpp
//  countingSort
//
//  Created by Shabre on 2017. 1. 27..
//  Copyright © 2017년 Shabre. All rights reserved.
//

#include <iostream>
#include <strings.h>
using namespace std;

int *inArr;
int *temp;
int maxVal;

void findMax(int size){
    for(int i=0; i<size; i++){
        if(inArr[i]>maxVal)
            maxVal=inArr[i];
    }
}

void setCounts(int *counts, int size){
    for(int i=0; i<size; i++)
        counts[inArr[i]]++;
    for(int i=0; i<maxVal; i++){
        counts[i+1]=counts[i]+counts[i+1];
    }
}

void setTemp(int *counts, int size){
    for(int i=size-1; i>=0; i--){
        temp[--counts[inArr[i]]]=inArr[i];
    }
}

int main(int argc, const char * argv[]) {
    int inputNum;
    cin>>inputNum;
    inArr=new int[inputNum];
    temp=new int[inputNum];
    for(int i=0; i<inputNum; i++){
        cin>>inArr[i];
    }
    maxVal=0;
    findMax(inputNum);
    
    int *counts=new int[maxVal+1];
    bzero(counts, sizeof(int)*(maxVal+1));
    setCounts(counts, inputNum);
    setTemp(counts, inputNum);
    
    
    for(int i=0; i<inputNum; i++){
        cout<<temp[i]<<endl;
    }
}
