#include <stdio.h>
#define MAX(x,y) (x>y?x:y)
int arr[10001];
int dp[10001];
int main(){
    int n,answer=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    dp[0]=0; dp[1]=arr[1]; dp[2]=arr[1]+arr[2];
    for(int i=3;i<=n;i++) {
        dp[i]=MAX(dp[i-1],arr[i]+dp[i-2]);
        dp[i]=MAX(dp[i],arr[i]+arr[i-1]+dp[i-3]);
    }
    printf("%d",dp[n]);
}