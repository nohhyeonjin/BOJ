#include <iostream>
#define MAX(x,y) (x>y?x:y)

int dp[2][301],score[301];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&score[i]);
    dp[0][1]=dp[1][1]=score[1];
    dp[0][2]=score[2]+score[1];
    dp[1][2]=score[2]+score[0];
    for(int i=3;i<=n;i++){
        dp[0][i]=score[i]+score[i-1]+MAX(dp[0][i-3],dp[1][i-3]);
        dp[1][i]=score[i]+MAX(dp[0][i-2],dp[1][i-2]);
    }
    printf("%d",MAX(dp[0][n],dp[1][n]));
}