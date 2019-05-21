//
//  main.cpp
//  quickSort
//
//  Created by Shabre on 2017. 1. 26..
//  Copyright © 2017년 Shabre. All rights reserved.
//

#include <iostream>
using namespace std;

int *inArr;

void quickSort(int left, int right){
    int originLeft=left;
    int originRight=right;
    int pivot=left;
    
    if(left>=right) return;
   
    do{
        do{
            left++;
        } while(inArr[left]<inArr[pivot]);
        while(inArr[right]>inArr[pivot]){
            right--;
        }
        if(left<right){
            int temp=inArr[left];
            inArr[left]=inArr[right];
            inArr[right]=temp;
        }
    }while(left<right);
    
    int temp;
    temp=inArr[pivot];
    inArr[pivot]=inArr[right];
    inArr[right]=temp;
    

    
    pivot=right;
    
    quickSort(originLeft, pivot-1);
    quickSort(pivot+1, originRight);
    
}


int main(int argc, const char * argv[]) {

    int inputNum;
    cin>>inputNum;
    inArr=new int[inputNum];
    for(int i=0; i<inputNum; i++){
        cin>>inArr[i];
    }
    
    quickSort(0, inputNum-1);
    
    for(int i=0; i<inputNum; i++){
        cout<<inArr[i]<<endl;
    }
    
    return 0;
}
