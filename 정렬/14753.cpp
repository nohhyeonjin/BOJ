#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> p,m;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        if(num>0) p.push_back(num);
        else m.push_back(num);
    }
    sort(p.begin(),p.end(),greater<int>());
    sort(m.begin(),m.end());
    int ans=0;
    //음수2개
    if(m.size()>=2) ans=max(ans,m[0]*m[1]);
    //음수2개*양수1개
    if(p.size()>=1) ans=max(ans,ans*p[0]);
    //양수2개
    if(p.size()>=2) ans=max(ans,p[0]*p[1]);
    //양수3개
    if(p.size()>=3) ans=max(ans,p[0]*p[1]*p[2]);
    printf("%d",ans);
}