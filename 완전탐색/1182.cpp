#include <bits/stdc++.h>
using namespace std;
int n,s;
int num[20];
int ans;
void dfs(int i,int sum){
    sum+=num[i];
    if(i==n) return;
    if(sum==s) ans++;
    //선택o
    dfs(i+1,sum);
    //선택x
    dfs(i+1,sum-num[i]);
}
int main(){
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    dfs(0,0);
    printf("%d",ans);
}