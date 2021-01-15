#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long r;
    while(1){
        r=a%b;
        if(r==0) break;
        a=b;
        b=r;
    }
    for(int i=0;i<b;i++) printf("1");
}