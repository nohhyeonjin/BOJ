#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int i=2;
    while(1){
        if(n==1) break;
        while(n%i!=0) i++;
        n/=i;
        printf("%d\n",i);
    }
}