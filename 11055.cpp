#include <iostream>
#define MAX(x,y) (x>y?x:y)

int dp[1001],a[1001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        dp[i]=a[i];
        for(int j=1;j<i;j++){
            if(a[j]<a[i])   dp[i]=MAX(dp[i],dp[j]+a[i]);
        }
    }
    int max=0;
    for(int i=1;i<=n;i++){
        if(max<dp[i]) max=dp[i];
    }
    printf("%d",max);
}