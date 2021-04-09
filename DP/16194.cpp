#include <iostream>
#include <algorithm>
using namespace std;
int n;
int p[1000];
int dp[1000];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++){
        dp[i]=p[i];
        for(int j=0;j<=i;j++) dp[i]=min(dp[i],dp[i-j]+p[j]);
    }
    cout << dp[n];
}