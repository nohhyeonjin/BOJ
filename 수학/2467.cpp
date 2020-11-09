#include <bits/stdc++.h>
using namespace std;
int n;
long long liquid[100000];
int main(){
    scanf("%d",&n);
    long long minVal=100000000000;
    long long val1, val2;
    for(int i=0;i<n;i++) scanf("%lld",&liquid[i]);
    int left=0,right=n-1;
    while(1){
        if(left>=right) break;
        long long value=liquid[left]+liquid[right];
        if(abs(value)<minVal){
            minVal=abs(value);
            val1=liquid[left];
            val2=liquid[right];
        }
        if(value>0) right--;
        else if(value<0) left++;
        else break;
    }
    printf("%lld %lld",val1, val2);
}