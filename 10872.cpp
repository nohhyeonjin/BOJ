#include <bits/stdc++.h>
using namespace std;
int factorial(int x){
    if(x==1||x==0) return 1;
    return factorial(x-1)*x;
}
int main(){
    int n;
    scanf("%d",&n);
    int ans=factorial(n);
    printf("%d",ans);
}