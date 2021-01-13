#include <bits/stdc++.h>
using namespace std;
long long dp[101];
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=3;i++) dp[i]=1;
    dp[4]=dp[5]=2;
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=6;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-5];
        }
        printf("%lld\n",dp[n]);
    }
}