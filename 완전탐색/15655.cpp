#include <bits/stdc++.h>
using namespace std;
int n,m;
int num[8];
int result[8];
bool selected[8];
void dfs(int idx, int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++) printf("%d ",result[i]);
        printf("\n");
    }
    for(int i=idx;i<n;i++){
        if(selected[i]) continue;
        selected[i]=true;
        result[cnt]=num[i];
        dfs(i+1,cnt+1);
        selected[i]=false;
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    sort(num,num+n);
    dfs(0,0);
}