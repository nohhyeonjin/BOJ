#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) printf("%d %d\n",v[i].first,v[i].second);
}