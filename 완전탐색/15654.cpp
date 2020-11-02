#include <bits/stdc++.h>
using namespace std;
int n,m;
int chk[9];
int arr[9];
int ans[9];
void dfs(int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++) printf("%d ",ans[i]);
        printf("\n");
        return;
    }
    for(int i=0;i<n;i++){
        if(chk[i]==0){
            chk[i]=1;
            ans[cnt]=arr[i];
            dfs(cnt+1);
            chk[i]=0;
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n);
    dfs(0);
}