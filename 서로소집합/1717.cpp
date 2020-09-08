#include <bits/stdc++.h>
using namespace std;
int n,m;
int parent[1000001];
int findParent(int x){
    if(x==parent[x]) return x;
    return parent[x]=findParent(parent[x]);
}
void unionParent(int a, int b){
    a=findParent(a);
    b=findParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a==0) unionParent(b,c);
        else{
            if(findParent(b)==findParent(c)) printf("YES\n");
            else printf("NO\n");
        }
    }
}