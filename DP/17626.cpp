#include <bits/stdc++.h>
using namespace std;
int n;
int dp[50001];
int main(){
    scanf("%d",&n);
    dp[1]=1;
    for(int i=2;i*i<=n;i++) dp[i*i]=1;
    for(int i=2;i<=n;i++){
        if(dp[i]!=0) continue;
        dp[i]=dp[1]+dp[i-1];
        for(int j=2;j*j<=i;j++){
            dp[i]=min(dp[i],dp[j*j]+dp[i-j*j]);
        }
    }
    printf("%d",dp[n]);
}