#include <iostream>
#define MAX(x,y) (x>y?x:y)

int dp[100001],array[100001];
int main(){
    int n,ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&array[i]);
    ans=dp[1]=array[1];
    for(int i=2;i<=n;i++){
        dp[i]=MAX(dp[i-1]+array[i],array[i]);
        ans=MAX(ans,dp[i]);
    }
    printf("%d",ans);
}