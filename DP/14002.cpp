#include <iostream>
using namespace std;
int n;
int a[1000];
int idx[1000];
int dp[1000];
int maxLen, maxIdx;
void go(int i, int len){
    if(len==maxLen){
        return;
    }
    go(idx[i],len+1);
    cout << a[i] << " ";
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        dp[i]=1;
        idx[i]=i;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    idx[i]=j;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dp[i]>maxLen){
            maxLen=dp[i];
            maxIdx=i;
        }    
    }
    cout << maxLen << "\n";
    go(maxIdx,0);
}