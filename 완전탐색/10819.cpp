#include <bits/stdc++.h>
using namespace std;
int n;
int num[8];
int ans;
void solve(int start, int end){
    if(start==end){
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum+=abs(num[i]-num[i+1]);
        }
        ans=max(ans,sum);
        return;
    }
    for(int i=start;i<=end;i++){
        swap(num[start],num[i]);
        solve(start+1,end);
        swap(num[start],num[i]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    solve(0,n-1);
    printf("%d",ans);
}