#include <bits/stdc++.h>
#define MAX(x,y) (x>y?x:y)
using namespace std;
int n;
vector<vector<int>> v;
int dp[500][500];
int main(){
    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){    
            int num;
            scanf("%d",&num);
            v[i].push_back(num);
        }
    }
    dp[0][0]=v[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(j==0) dp[i][j]=v[i][j]+dp[i-1][j];
            else if(j==i) dp[i][j]=v[i][j]+dp[i-1][j-1];
            else dp[i][j]=v[i][j]+MAX(dp[i-1][j-1],dp[i-1][j]);
            //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) ans=MAX(ans,dp[n-1][i]);
    printf("%d",ans);
}