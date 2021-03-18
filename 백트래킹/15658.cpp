#include <iostream>
using namespace std;
int n;
int num[11];
int cnt[4];
int minAns=1e9,maxAns=-1e9;
void dfs(int plus, int minus, int mul, int div, int idx, int sum){
    if(idx==n){
        if(sum<minAns) minAns=sum;
        if(sum>maxAns) maxAns=sum;
        return;
    }

    if(plus-1>=0) dfs(plus-1,minus,mul,div,idx+1,sum+num[idx]);
    if(minus-1>=0) dfs(plus,minus-1,mul,div,idx+1,sum-num[idx]);
    if(mul-1>=0) dfs(plus,minus,mul-1,div,idx+1,sum*num[idx]);
    if(div-1>=0) dfs(plus,minus,mul,div-1,idx+1,sum/num[idx]);
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> num[i];
    for(int i=0;i<4;i++) cin >> cnt[i];
    dfs(cnt[0],cnt[1],cnt[2],cnt[3],1,num[0]);
    cout << maxAns << "\n" << minAns;
}