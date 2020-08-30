#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
int dp[21];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t,p;
        scanf("%d %d",&t,&p);
        v.push_back(make_pair(t,p));
    }
    for(int i=n-1;i>=0;i--){
        int t=v[i].first;
        int p=v[i].second;
        if(i+t>n) dp[i]=0;
        else dp[i]=p+dp[i+t];
        for(int j=i+1;j<i+t;j++) dp[i]=max(dp[i],dp[j]);
    }
    printf("%d",dp[0]);
}