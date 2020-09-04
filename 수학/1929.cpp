#include <bits/stdc++.h>
using namespace std;
int m,n;
vector<int> ans;
int main(){
    scanf("%d %d",&m,&n);
    ans.resize(n+1);
    for(int i=2;i<=n;i++) ans[i]=i;
    for(int i=2;i<=n;i++){
        if(ans[i]==0) continue;
        for(int j=i*2;j<=n;j+=i) ans[j]=0;
    }
    for(int i=m;i<=n;i++){
        if(i!=1&&ans[i]!=0) printf("%d\n",i);
    }
}