#include <bits/stdc++.h>
#define MAX 10000001
using namespace std;
int arr[MAX];
vector<int> prime;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++) arr[i]=i;
    for(int i=2;i<=n;i++){
        if(arr[i]==0) continue;
        for(int j=i*2;j<=n;j+=i) arr[j]=0;
    }
    for(int i=2;i<=n;i++) if(arr[i]!=0) prime.push_back(i);
    int idx=0;
    while(1){
        if(n==1) break;
        while(n%prime[idx]!=0) idx++; 
        n=n/prime[idx];
        printf("%d\n",prime[idx]);
    }
}