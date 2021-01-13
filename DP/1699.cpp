#include <bits/stdc++.h>
using namespace std;
int dp[100001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i*i<=n;i++) dp[i*i]=1;
    for(int i=2;i<=n;i++){
        if(dp[i]==1) continue;
        dp[i]=1+dp[i-1];
        for(int j=2;j*j<=i;j++){
            dp[i]=min(dp[i],1+dp[i-j*j]);
        }
    }
    printf("%d",dp[n]);
}