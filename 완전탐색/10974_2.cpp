#include <bits/stdc++.h>
using namespace std;
int n;
bool s[9];
vector<int> v;
void dfs(int cnt){
    if(cnt==n){
        for(int i=0;i<v.size();i++) printf("%d ",v[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(s[i]) continue;
        s[i]=true;
        v.push_back(i);
        dfs(cnt+1);
        v.pop_back();
        s[i]=false;
    }
}
int main(){
    scanf("%d",&n);
    dfs(0);
}