#include <iostream>
#define MIN(x,y) ((x)<(y)?(x):(y))

int main(){
    int n;
    int dp[1000001];
    dp[0]=dp[1]=0;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+1;
        if(i%2==0) dp[i]=MIN(dp[i],dp[i/2]+1);
        if(i%3==0) dp[i]=MIN(dp[i],dp[i/3]+1);
    }
    printf("%d",dp[n]);
}