#include <bits/stdc++.h>
using namespace std;
int v,e;
int parent[101];
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
    cin >> v >> e;
    for(int i=1;i<=v;i++) parent[i]=i;
    bool cycle=false;
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        //모든 edge확인하며 부모가 같으면 사이클 발생했다고 판단
        if(findParent(a)==findParent(b)){
            cycle=true;
            break;
        }else{
            unionParent(a,b);
        }
    }
    if(cycle==true) cout << "cycle 발생" << "\n";
    else cout << "cycle 발생하지않음" << "\n";
}