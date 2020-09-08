#include <bits/stdc++.h>
using namespace std;
int v,e;
int parent[101];
int findParent(int x){
    //루트 노드면 x return 아니면 부모의 부모를 찾아서 return
    if(x==parent[x]) return x;
    //경로압축 시
    /*return parent[x]=findParent(parent[x]);*/
    return findParent(parent[x]);
}
//선그어주는작업(같은 집합에 넣어줌)
void unionParent(int a, int b){
    a=findParent(a);
    b=findParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}
int main(){
    cin >> v >> e;
    for(int i=1;i<=v;i++) parent[i]=i;
    
    //union
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        unionParent(a,b);
    }
    
    //find
    for(int i=1;i<=v;i++) cout << findParent(i) << "\n";
    for(int i=1;i<=v;i++) cout << parent[i] << "\n";
}