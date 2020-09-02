#include <bits/stdc++.h>
using namespace std;
int n;
int soldier[2000];
int dp[2000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&soldier[i]);
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(soldier[i]<soldier[j]&&dp[j]+1>dp[i]) dp[i]=dp[j]+1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) ans=max(ans,dp[i]);
    printf("%d",n-ans);
}