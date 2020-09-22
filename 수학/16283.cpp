#include <bits/stdc++.h>
using namespace std;
int a, b, n, w;
int main(){
    scanf("%d %d %d %d",&a,&b,&n,&w);
    int ans;
    int cnt=0;
    bool e=false;
    for(int i=1;i<n;i++){
        int y=i;
        int x=n-y;
        if((a*x+b*y)==w){
            ans=i;
            cnt++;
            e=true;
        }
    }
    if(e==false||cnt>=2) printf("-1");
    else printf("%d %d",n-ans,ans);
}