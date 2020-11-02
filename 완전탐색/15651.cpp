#include <bits/stdc++.h>
using namespace std;
int n,m;
int chk[8];
int arr[8];
void dfs(int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++) printf("%d ",arr[i]);
        printf("\n");
        return;
    }
    for(int i=0;i<n;i++){
        arr[cnt]=i+1;
        dfs(cnt+1);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    dfs(0);
}