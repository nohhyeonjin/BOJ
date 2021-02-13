#include <bits/stdc++.h>
using namespace std;
int n,m;
int plan[1001];
int parent[201];
int findParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x]);
}
void unionParent(int a,int b){
    a=findParent(a);
    b=findParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a;
            scanf("%d",&a);
            if(a==1) unionParent(i,j);
        }
    }
    for(int i=1;i<=m;i++) scanf("%d",&plan[i]);
    bool canGo=true;
    for(int i=1;i<=m-1;i++){
        int s=plan[i];
        int e=plan[i+1];
        if(findParent(s)!=findParent(e)){
            canGo=false;
            break;
        }
    }
    if(canGo) printf("YES");
    else printf("NO");
}