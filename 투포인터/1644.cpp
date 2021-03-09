#include <bits/stdc++.h>
using namespace std;
int n;
int arr[4000001];
vector<int> prime;
int main(){
    scanf("%d",&n);
    //에라토스테네스의 체
    for(int i=2;i<=n;i++) arr[i]=i;
    for(int i=2;i<=n;i++){
        if(arr[i]==0) continue;
        for(int j=i*2;j<=n;j+=i) arr[j]=0;
    }
    for(int i=2;i<=n;i++){
        if(arr[i]!=0) prime.push_back(i);
    }

    //연속된 소수의 합
    int ans=0;
    int s=0,e=0;
    int sum=0;
    while(1){
        if(sum==n) ans++;
        if(sum>=n){
            sum-=prime[s];
            s++;
        }else if(e==prime.size()) break;
        else{
            sum+=prime[e];
            e++;
        }
    }
    printf("%d",ans);
}