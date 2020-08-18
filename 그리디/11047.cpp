#include <bits/stdc++.h>
int money[10];
int main(){
    int n,k;
    int cnt=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&money[i]);
    for(int i=n-1;i>=0;i--){
        if(money[i]<=k){
           cnt+=k/money[i];
           k=k%money[i];
        }
    }
    printf("%d",cnt);
}