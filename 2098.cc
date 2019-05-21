#include <cstdio>
#include <cstring>
#define min(a,b) (a>b)? b:a

int N, start;
int map[16][16];
int tmp[16][65536];
const int m=160000000;

int dp(int cur, int vis) {
    if(vis == (1<<N)-1)
        return map[cur][start]?map[cur][start]:m;
    int &ret = tmp[cur][vis];
    if(ret != -1) 
        return ret;
    ret = m;
    for(int i=0; i<N; i++) {
        if(vis & (1<<i))
            continue;
        if(map[cur][i]==0)
            continue;
        
        ret = min(ret, dp(i, vis | (1<<i)) + map[cur][i]);
    }
    return ret;
}

int main() {
    scanf("%d",&N);

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d",&map[i][j]);
        }
    }
    memset(tmp, -1, sizeof(tmp));
    printf("%d\n",dp(0, 1));
}
