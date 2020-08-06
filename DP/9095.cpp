#include <iostream>

int dp[11];
int main(){
    int t,n;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        for(int j=4;j<=n;j++){
            dp[j]=dp[j-1]+dp[j-2]+dp[j-3];
        }
        printf("%d\n",dp[n]);
    }
}