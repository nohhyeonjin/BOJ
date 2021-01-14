#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) printf("%d %d\n",v[i].second, v[i].first);
}