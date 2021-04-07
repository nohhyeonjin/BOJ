#include <iostream>
using namespace std;
int n;
int t[15], p[15];
int ans;
void go(int idx, int sum){
    if(idx>n) return;
    if(idx==n){
        if(sum>ans) ans=sum;
        return;
    }
    go(idx+t[idx],sum+p[idx]);
    go(idx+1,sum);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> t[i] >> p[i];
    go(0,0);
    cout << ans;
}