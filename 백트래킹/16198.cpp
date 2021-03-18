#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n,ans;
int w[10];
bool selected[10];
void solve(int sum,int cnt){
    if(cnt==n-2){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<n-1;i++){
        if(selected[i]) continue;
        selected[i]=true;
        int l=i,r=i;
        while(selected[l]) l--;
        while(selected[r]) r++;
        solve(sum+w[l]*w[r],cnt+1);
        selected[i]=false;
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> w[i];
    solve(0,0);
    cout << ans;
}