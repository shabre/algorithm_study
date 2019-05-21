//
//  main.cpp
//  절대값
//
//  Created by Shabre on 2018. 3. 22..
//  Copyright © 2018년 Shabre. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b;
    printf("첫번째 값 입력:");
    scanf("%d",&a);
    printf("두번째 값 입력:");
    scanf("%d",&b);
    int result = a - b;
    
    int abs = result * ((result>0) - (result < 0));
    printf("|%d - %d| = %d\n",a,b,abs);
    
    return 0;
}
