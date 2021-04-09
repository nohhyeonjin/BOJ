#include <iostream>
#define MOD 1000000009
using namespace std;
int dp[100001][3];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=3;i++) dp[i][i]=1;
        dp[3][1]=dp[3][2]=1;
        for(int i=4;i<=n;i++){
            dp[i][1]=(dp[i-1][2]+dp[i-1][3])%MOD;
            dp[i][2]=(dp[i-2][1]+dp[i-2][3])%MOD;
            dp[i][3]=(dp[i-3][1]+dp[i-3][2])%MOD;
        }
        int ans=0;
        for(int i=1;i<=3;i++) ans=(ans+dp[n][i])%MOD;
        cout << ans%MOD << "\n";
    }
}