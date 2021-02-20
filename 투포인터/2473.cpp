#include <bits/stdc++.h>
using namespace std;
long long amount[5000];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&amount[i]);
    sort(amount,amount+n);
    long long minValue=LLONG_MAX;
    long long aA,aB,aC;
    for(int i=0;i<n-2;i++){
        int a=i, b=i+1, c=n-1;
        while(b<c){
            long long sum=amount[a]+amount[b]+amount[c];
            if(abs(sum)<minValue){
                minValue=abs(sum);
                aA=amount[a]; aB=amount[b]; aC=amount[c];
            }
            if(sum<0) b++;
            else c--;
        }
    }
    printf("%lld %lld %lld",aA,aB,aC);
}