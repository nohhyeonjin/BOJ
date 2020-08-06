#include <iostream>
#define MAX(x,y) (x>y?x:y)

int dp[2][100001],num[2][100001];
int main(){
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        for(int j=0;j<2;j++){
            for(int k=1;k<=n;k++) scanf("%d",&num[j][k]);
        }
        dp[0][1]=num[0][1];
        dp[1][1]=num[1][1];
        for(int j=2;j<=n;j++){
            dp[0][j]=num[0][j]+MAX(dp[1][j-1],dp[1][j-2]);
            dp[1][j]=num[1][j]+MAX(dp[0][j-1],dp[0][j-2]);
        }
        printf("%d\n",MAX(dp[0][n],dp[1][n]));
    }
}