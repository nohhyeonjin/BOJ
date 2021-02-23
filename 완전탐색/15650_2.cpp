#include <bits/stdc++.h>
using namespace std;
int n,m;
bool selected[9];
void dfs(int idx, int cnt){
    if(cnt==m){
        for(int i=1;i<=n;i++) if(selected[i]) printf("%d ",i);
        printf("\n");
        return;
    }
    for(int i=idx;i<=n;i++){
        if(selected[i]) continue;
        selected[i]=true;
        dfs(i+1,cnt+1);
        selected[i]=false;
    }
}
int main(){
    scanf("%d %d",&n,&m);
    dfs(1,0);
}