#include <iostream>

long long int dp[91][2];
int main(){
    int n;
    long long int ans=0;
    scanf("%d",&n);
    dp[1][0]=0; dp[1][1]=1;
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    for(int i=0;i<2;i++) ans+=dp[n][i];
    printf("%lld",ans);
}