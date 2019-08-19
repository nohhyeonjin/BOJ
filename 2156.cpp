#include <iostream>
#define MAX(x,y) (x>y?x:y)

int dp[10001], amount[10001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&amount[i]);
    dp[0]=0; dp[1]=amount[1]; dp[2]=amount[1]+amount[2];
    for(int i=3;i<=n;i++){
        dp[i]=MAX(dp[i-1],dp[i-2]+amount[i]);
        dp[i]=MAX(dp[i],dp[i-3]+amount[i]+amount[i-1]);
    }
    printf("%d",dp[n]);
}