#include <bits/stdc++.h>
using namespace std;
long long amount[100000];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&amount[i]);
    sort(amount,amount+n);
    int s=0,e=n-1;
    long long minValue=LLONG_MAX;
    long long l,r;
    while(s<e){
        long long sum=amount[s]+amount[e];
        if(llabs(sum)<minValue){
            l=amount[s];
            r=amount[e];
            minValue=llabs(sum);
        }
        if(sum<0) s++;
        else e--;
    }
    printf("%lld %lld",l,r);
}