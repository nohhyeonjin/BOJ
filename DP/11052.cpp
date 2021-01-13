#include <bits/stdc++.h>
using namespace std;
int dp[1001];
int arr[1001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++){
        dp[i]=arr[i];
        for(int j=i-1;j>0;j--){
            dp[i]=max(dp[i],dp[j]+arr[i-j]);
        }
    }
    printf("%d",dp[n]);
}