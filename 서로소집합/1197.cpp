#include <bits/stdc++.h>
using namespace std;
int ans;
vector<pair<int,pair<int,int>>> edges;
int parent[10001];
int find_parent(int x){
    if(parent[x]==x) return x;
    return parent[x]=find_parent(parent[x]);
}
void union_parent(int a, int b){
    a=find_parent(a);
    b=find_parent(b);
    if(b<a) swap(a,b);
    parent[b]=a;
}
int main(){
    int v,e;
    scanf("%d %d",&v,&e);
    for(int i=1;i<=v;i++) parent[i]=i;
    for(int i=0;i<e;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edges.push_back({c,{a,b}});
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++){
        int a=edges[i].second.first;
        int b=edges[i].second.second;
        int cost=edges[i].first;
        if(find_parent(a)!=find_parent(b)){
            union_parent(a,b);
            ans+=cost;
        }
    }
    printf("%d",ans);
}