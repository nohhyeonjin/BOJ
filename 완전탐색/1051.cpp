#include <bits/stdc++.h>
using namespace std;
int n,m;
int box[50][50];
int ans;
void dfs(int y, int x, int size){
    int ry=y+size-1;
    int rx=x+size-1;
    if(rx>=m){
        dfs(y+1,0,size);
        return;
    }
    if(ry>=n) return;
    if(box[y][x]==box[y][rx]&&box[y][rx]==box[ry][x]&&box[ry][x]==box[ry][rx]){
        ans=max(ans,size*size);
        return;
    }
    dfs(y,x+1,size);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) scanf("%1d",&box[i][j]);
    }
    for(int i=1;i<=min(m,n);i++) dfs(0,0,i);
    printf("%d",ans);
}