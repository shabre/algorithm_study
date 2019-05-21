#include <cstdio>                                                     
#include <string.h>                                                   
using namespace std;                                                  
                                                                      
typedef long long ll;                                                 
#define mod 1000000

ll go(int idx, ll *dp, char* command, int len){                                                 
  if(idx == len-1) return 1;                                    
  if(dp[idx]) return dp[idx];                                             
                                                            
  if(command[idx+1] == '0') 
  {                                   
      if(idx != len - 2) dp[idx] += go(idx + 2, dp, command, len);
      else dp[idx] += 1;   
      
      dp[idx] %= mod;                                                          
      return dp[idx];                                           
  }                                                             
                                                                
  if((command[idx]-'0')*10 + (command[idx+1]-'0') <= 26)
  {       
    if(idx == len - 2) dp[idx] += 1;
    else
    { 
      if(command[idx+2] != '0') dp[idx] += go(idx + 2, dp, command, len);
      else
      {
          dp[idx] += go(idx + 1, dp, command, len);
          dp[idx] %= mod;
          return dp[idx];
      }
    }                                            
    dp[idx] %= mod;
  } 
    
  dp[idx] += go(idx + 1, dp, command, len);                                       
  dp[idx] %= mod;                                                            
  return dp[idx];                                               
}                                                                                                                                  
int main(void){  
  ll dp[5011];                                                          
  char command[5011];                                                   
  int len = 0; 
  
  scanf("%s", command);                                               
  len = strlen(command);  
  if(len == 1 && command[0] == '0'){
      printf("0\n");
      return 0;
  }
  for(int i = 0;i <= len +2; i++) dp[i] = 0;
  printf("%lld\n", go(0,dp, command, len));   
}
