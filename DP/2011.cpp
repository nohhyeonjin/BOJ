#include <bits/stdc++.h>
#define MOD 1000000
using namespace std;
int dp[5001];
int num[5001];
int main(){
    string s;
    cin >> s;
    for(int i=1;i<=s.length();i++) num[i]=s[i-1]-'0';
    dp[0]=1;
    for(int i=1;i<=s.length();i++){
        if(num[i]!=0) dp[i]=dp[i-1];
        int val=num[i-1]*10+num[i];
        if(10<=val&&val<=26) dp[i]=(dp[i]+dp[i-2])%MOD;
    }
    printf("%d",dp[s.length()]);
}