#include <bits/stdc++.h>
using namespace std;
int n;
int dp[100002];
int main(){
    scanf("%d",&n);
    int val=2;
    for(int i=1;i<=n;i=i+2){
        dp[i]=dp[i+1]=val;
        val=(val*2)%16769023;
    }
    printf("%d",dp[n]);
}