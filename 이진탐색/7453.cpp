#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long table[4000][4];
vector<long long> l,r;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++) scanf("%lld",&table[i][j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            l.push_back(table[i][0]+table[j][1]);
            r.push_back(table[i][2]+table[j][3]);
        }
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    for(int i=0;i<l.size();i++){
        long long cur=l[i];
        int idx=lower_bound(r.begin(),r.end(),-cur)-r.begin();
        if(cur==-r[idx]) ans+=(upper_bound(r.begin(),r.end(),-cur)-lower_bound(r.begin(),r.end(),-cur));
    }
    printf("%lld",ans);
}