#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    int r;
    while(1){
        r=a%b;
        if(r==0) break;
        a=b;
        b=r;
    }
    return b;
}
void lcm(int a,int b){
    printf("%d\n",a*b/gcd(a,b));
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        lcm(a,b);
    }
}