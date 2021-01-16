#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    vector<int> v;
    while(!q.empty()){
        for(int i=0;i<k-1;i++){
            int front=q.front();
            q.push(front);
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
    }
    printf("<");
    for(int i=0;i<v.size()-1;i++) printf("%d, ",v[i]);
    printf("%d>",v[v.size()-1]);
}