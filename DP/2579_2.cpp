#include <bits/stdc++.h>
using namespace std;
int dp[10001];
int main(){
    int n;
    scanf("%d",&n);
    int num[10001];
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    dp[0]=0;
    dp[1]=num[1];
    dp[2]=num[1]+num[2];
    for(int i=3;i<=n;i++) dp[i]=max(num[i]+dp[i-2],num[i]+num[i-1]+dp[i-3]);
    printf("%d",dp[n]);
}