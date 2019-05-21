//
//  main2.cpp
//  6603
//
//  Created by kihwan kim on 2017. 7. 15..
//  Copyright © 2017년 kihwan kim. All rights reserved.
//
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void DFS(vector<int>& arr, vector<int>& stack, int from)
{
    if (stack.size() == 6)
    {
        for (int i = 0; i < 6; i++)
            printf("%d ", stack[i]);
        puts("");
        return;
    }
    
    else {
        for (int i = from + 1; i < arr.size(); i++) {
            
            stack.push_back(arr[i]);
            DFS(arr, stack, i);
            stack.pop_back();
        }
    }
}

int main()
{
    
    int n;
    
    
    while (scanf("%d",&n), n != 0){
        
        vector<int> numbers(n), stack;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &numbers[i]);
        }
        
        for (int i = 0; n - i >= 6; i++)
        {
            stack.push_back(numbers[i]);
            DFS(numbers, stack, i);
            stack.pop_back();
        }
        puts("");
    }
    
    return 0;
}
