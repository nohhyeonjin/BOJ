#include <bits/stdc++.h>
using namespace std;
int n,x;
int main(){
    scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        if(num<x) printf("%d ",num); 
    }
}