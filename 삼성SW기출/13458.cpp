#include <bits/stdc++.h>
using namespace std;
int n,b,c;
int num[1000000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    scanf("%d %d",&b,&c);
    long long ans=0;
    for(int i=0;i<n;i++){
        int sum=num[i];
        sum-=b;
        ans++;
        if(sum<=0) continue;
        ans+=sum/c;
        if(sum%c>0) ans++;
    }
    printf("%lld",ans);
}