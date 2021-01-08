#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int start, end;
        scanf("%d %d",&start,&end);
        v.push_back({end,start});
    } 
    sort(v.begin(),v.end());
    int end=0,ans=0;
    for(int i=0;i<n;i++){
        if(v[i].second>=end){
            end=v[i].first;
            ans++;
        }
    }
    printf("%d",ans);
}