#include <bits/stdc++.h>
using namespace std;
int n,s;
int arr[100000];
int ans=1e9;
int main(){
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int sum=0;
    int left=0, right=0;
    int len=0;
    while(1){
        if(sum>=s){
            ans=min(ans,len);
            sum-=arr[left++];
            len--;
        }else if(right==n) break;
        else{
            sum+=arr[right++];
            len++;
        }
    }
    if(ans!=1e9) printf("%d",ans);
    else printf("0");
}