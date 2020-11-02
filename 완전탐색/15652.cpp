#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[8];
void dfs(int start, int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++) printf("%d ",arr[i]);
        printf("\n");
        return;
    }
    for(int i=start;i<n;i++){
        arr[cnt]=i+1;
        dfs(i,cnt+1);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    dfs(0,0);
}