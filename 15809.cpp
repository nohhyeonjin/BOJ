#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> soldier={0};
int parent[100001];
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
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        soldier.push_back(num);
    }
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a==1){
            //동맹
            int root=min(findParent(b),findParent(c));
            int leaf=max(findParent(b),findParent(c));
            unionParent(b,c);
            soldier[root]+=soldier[leaf];
        }else{
            //전쟁
            int bRoot=findParent(b);
            int cRoot=findParent(c);
            int root=min(bRoot,cRoot);
            unionParent(b,c);
            if(soldier[bRoot]==soldier[cRoot]){
                soldier[root]=0;
            }else{
                soldier[root]=abs(soldier[bRoot]-soldier[cRoot]);
            }
        }
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        if(soldier[findParent(i)]!=0) s.insert(findParent(i));
    }
    set<int>::iterator iter;
    printf("%d\n",s.size());
    vector<int> ans;
    for(iter=s.begin();iter!=s.end();iter++) ans.push_back(soldier[*iter]);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
}