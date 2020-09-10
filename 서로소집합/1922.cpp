#include <bits/stdc++.h>
using namespace std;
int n,m;
int result;
int parent[1001];
vector<pair<int, pair<int,int>>> edges;
int findParent(int x){
    if(x==parent[x]) return x;
    return parent[x]=findParent(parent[x]);
}
void unionParent(int a, int b){
    a=findParent(a);
    b=findParent(b);
    if(a!=b){
        if(a>b) swap(a,b);
        parent[b]=a;
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        int a,b,cost;
        scanf("%d %d %d",&a,&b,&cost);
        edges.push_back({cost,{a,b}});
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<m;i++){
        int cost=edges[i].first;
        int a=edges[i].second.first;
        int b=edges[i].second.second;
        if(findParent(a)!=findParent(b)){
            unionParent(a,b);
            result+=cost;
        }
    }
    printf("%d",result);
}