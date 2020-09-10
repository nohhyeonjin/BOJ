#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
        dp[i][1]=i;
        dp[i][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){
            if(i-1<j) break;
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%10007;
        }
    }
    printf("%d",dp[n][k]%10007);
}