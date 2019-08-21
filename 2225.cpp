#include <iostream>
#define MOD 1000000000
long long dp[201][201];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<=k;i++) dp[0][i]=1;
    for(int i=1;i<=k;i++) dp[1][i]=i;

    for(int j=2;j<=n;j++){
        for(int l=1;l<=k;l++){
            for(int i=0;i<=n;i++){
                dp[j][l]+=(dp[i][l-1]%MOD);
            }
        }
    }
    printf("%lld",dp[n][k]%MOD);
}