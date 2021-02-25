#include <iostream>
#include <vector>
using namespace std;
int n,m;
int know;
int parent[51];
vector<vector<int>> party;
int findParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x]);
}
void unionParent(int a, int b){
    a=findParent(a);
    b=findParent(b);
    if(a>b) swap(a,b);
    parent[b]=a;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) parent[i]=i;
    scanf("%d",&know);
    int prev=0;
    for(int i=0;i<know;i++){
        int cur;
        scanf("%d",&cur);
        unionParent(prev,cur);
    }
    int ans=0;
    for(int i=0;i<m;i++){
        vector<int> v;
        int cnt;
        scanf("%d",&cnt);
        for(int j=0;j<cnt;j++){
            int num;
            scanf("%d",&num);
            v.push_back(num);
        }
        party.push_back(v);
        int prev;
        if(!v.empty()) prev=v[0];
        for(int j=1;j<cnt;j++){
            int cur=v[j];
            unionParent(prev,cur);
            prev=cur;
        }
    }
    for(int i=0;i<m;i++){
        vector<int> v=party[i];
        if(!v.empty()){
            if(findParent(v[0])!=0) ans++;
        }
    }
    printf("%d",ans);
}