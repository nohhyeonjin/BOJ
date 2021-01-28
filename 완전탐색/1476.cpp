#include <bits/stdc++.h>
using namespace std;
int main(){
    int e,s,m;
    scanf("%d %d %d",&e,&s,&m);
    int ans=0;
    while(1){
        ans++;
        int ne=ans%15;
        if(ne==0) ne=15;
        int ns=ans%28;
        if(ns==0) ns=28;
        int nm=ans%19;
        if(nm==0) nm=19;
        if(ne==e&&ns==s&&nm==m) break;
    }    
    printf("%d",ans);
}