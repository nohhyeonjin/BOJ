#include <bits/stdc++.h>
using namespace std;
int n,s;
int num[20];
int ans;
int result[20];
bool selected[20];
void dfs(int idx, int depth, int cnt){
    if(depth==cnt){
        int sum=0;
        for(int i=0;i<cnt;i++) sum+=result[i];
        if(sum==s) ans++;
        return;
    }
    for(int i=idx;i<n;i++){
        if(selected[i]) continue;
        selected[i]=true;
        result[depth]=num[i];
        dfs(i+1,depth+1,cnt);
        selected[i]=false;
    }
}
int main(){
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    for(int i=1;i<=n;i++) dfs(0,0,i);
    printf("%d",ans);
}