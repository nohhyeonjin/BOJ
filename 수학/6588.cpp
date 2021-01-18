#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int main(){
    //에라토스테네스의 체
    for(int i=2;i<=1000000;i++) arr[i]=i;
    for(int i=2;i<=1000000;i++){
        if(arr[i]==0) continue;
        for(int j=i*2;j<=1000000;j+=i) arr[j]=0;
    }
    //짝수 지우기
    for(int i=2;i<=1000000;i+=2) arr[i]=0; 
    while(1){
        int t;
        scanf("%d",&t);
        if(t==0) break;
        int a,b;
        bool flag=false;
        for(int i=3;i<=1000000;i++){
            if(arr[i]==0) continue;
            a=i;
            b=t-a;
            if(arr[b]!=0){
                flag=true;
                break;
            }
        }
        if(flag) printf("%d = %d + %d\n",t,a,b);
        else printf("Goldbach's conjecture is wrong.\n");
    }
}