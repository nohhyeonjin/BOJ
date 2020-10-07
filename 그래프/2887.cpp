#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
int n, ans;
vector<pair<int,int>> v[3]; //{좌표,행성번호}
vector<pair<int,pair<int,int>>> vgap;    //{차,{번호1, 번호2}}
int parent[MAX];
int find_parent(int x){
    if(x==parent[x]) return x;
    return parent[x]=find_parent(parent[x]);
}
void union_parent(int a, int b){
    a=find_parent(a);
    b=find_parent(b);
    if(a>b) swap(a,b);
    parent[b]=a;
}
int main(){
    //입력
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        v[0].push_back({x,i});
        v[1].push_back({y,i});
        v[2].push_back({z,i});
    }
    //초기화
    for(int i=1;i<=n;i++) parent[i]=i;
    //정렬
    for(int i=0;i<3;i++) sort(v[i].begin(),v[i].end());
    for(int i=0;i<3;i++){
        for(int j=0;j<n-1;j++){
            int gap=abs(v[i][j].first-v[i][j+1].first);
            vgap.push_back({gap,{v[i][j].second,v[i][j+1].second}});
        }
    }
    sort(vgap.begin(),vgap.end());
    for(int i=0;i<vgap.size();i++){
        int a=vgap[i].second.first, b=vgap[i].second.second;
        int cost=vgap[i].first;
        if(find_parent(a)!=find_parent(b)){
            union_parent(a,b);
            ans+=cost;
        }
    }
    printf("%d",ans);
}