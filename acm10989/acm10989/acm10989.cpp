#include <iostream>
#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    const int MAX = 10001;
    int *arrp = new int[MAX];
    int *arrm = new int[MAX];
    
    memset(arrp, 0 , MAX * sizeof(int));
    memset(arrm, 0 , MAX * sizeof(int));
    
    int cnt = 0;
    scanf("%d", &cnt);
    int mcnt = 0;
    int pcnt = 0;
    int input;
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &input);
        if(input<0){
            arrm[abs(input)]  += 1;
            mcnt+=1;
        }
        else{
            arrp[input] += 1;
            pcnt+=1;
        }
    }
    int rcnt = 0;
    for (int i = MAX; i>=0; i--) {
        if(arrm[i] > 0) {
            for(int j = 0; j<arrm[i]; j++){
                printf("%d\n", -i);
                rcnt+=1;
            }
        }
        if(rcnt==mcnt)
            break;
    }
    
    rcnt = 0;
    for (int i = 0; i<MAX; i++) {
        if(arrp[i] > 0) {
            for(int j =0; j<arrp[i]; j++) {
                printf("%d\n", i);
                rcnt+=1;
            }
        }
        if(rcnt==pcnt)
            break;
    }
    
    return 0;
}


