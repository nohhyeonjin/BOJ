#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    if(y>x) swap(x,y);
    int r;
    while(1){
        r=x%y;
        if(r==0) break;
        x=y;
        y=r;
    }
    return y;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[100];
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sum+=gcd(arr[i],arr[j]);
            }
        }
        printf("%lld\n",sum);
    }
}