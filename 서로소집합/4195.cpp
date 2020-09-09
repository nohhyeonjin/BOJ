#include <bits/stdc++.h>
using namespace std;
map<string,int> m;
int parent[100001];
int cnt[100001];
int findParent(int x){
    if(x==parent[x]) return x;
    return parent[x]=findParent(parent[x]);
}
int unionParent(int a, int b){
    a=findParent(a);
    b=findParent(b);
    if(a!=b){
        if(cnt[a]<cnt[b]) swap(a,b);
        cnt[a]+=cnt[b];
        parent[b]=a;
        cnt[b]=0;
    }
    return cnt[a];
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        m.clear();
        int f;
        scanf("%d",&f);
        int idx=1;
        for(int j=0;j<100001;j++){
            parent[j]=j;
            cnt[j]=1;
        }
        for(int j=0;j<f;j++){
            char a[21],b[21];
            scanf("%s %s",a,b);
            if(m.count(a)==0) m.insert(make_pair(a,idx++));
            if(m.count(b)==0) m.insert(make_pair(b,idx++));
            printf("%d\n",unionParent(m[a],m[b]));
        }
    }
}