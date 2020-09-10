#include <bits/stdc++.h>
using namespace std;
int v,e;
int parent[101];
int result;
vector<pair<int,pair<int,int>>> edge;   //cost,(start edge,end edge)
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
    cin >> v >> e;
    for(int i=1;i<=v;i++) parent[i]=i;
    for(int i=0;i<e;i++){
        int a,b,c;
        //edge a,b와 cost c
        cin >> a >> b >> c;
        edge.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(edge.begin(),edge.end());
    for(int i=0;i<e;i++){
        int cost=edge[i].first;
        int a=edge[i].second.first;
        int b=edge[i].second.second;
        if(findParent(a)!=findParent(b)){   //부모가 같지않으면(사이클이 생성되지않으면)
            unionParent(a,b);
            result+=cost;
        }
    }
    printf("%d",result);
}