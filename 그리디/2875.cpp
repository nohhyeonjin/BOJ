#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int ans=min(n/2,m);
    n=n-2*ans;
    m=m-ans;
    k=k-(n+m);
    while(k>0){
        ans=ans-1;
        k=k-3;
    }
    printf("%d",ans);
}