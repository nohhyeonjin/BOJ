#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    int r;
    while(1){
        r=x%y;
        if(r==0) break;
        x=y;
        y=r;
    }
    return y;   
}
int lcm(int x, int y, int r){
    return x*y/r;
}
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    if(y>x) swap(x,y);
    printf("%d\n%d",gcd(x,y),lcm(x,y,gcd(x,y)));
}