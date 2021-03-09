#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[10000];
int ans;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int left=0, right=0;
    int sum=0;
    while(1){
        if(sum>=m) sum-=arr[left++];
        else if(right==n) break;
        else sum+=arr[right++];
        if(sum==m) ans++;
    }
    printf("%d",ans);
}