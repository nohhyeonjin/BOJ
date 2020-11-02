#include <bits/stdc++.h>
using namespace std;
int n,m;
int chk[9];
int arr[9];
void dfs(int s, int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++) printf("%d ",arr[i]);
        printf("\n");
        return;
    }
    for(int i=s;i<=n;i++){
        if(chk[i]==0){
            chk[i]=1;
            arr[cnt]=i;
            dfs(i+1,cnt+1);
            chk[i]=0;
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    dfs(1, 0);
}