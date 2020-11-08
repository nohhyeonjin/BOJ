#include <bits/stdc++.h>
#define MAX 10001
using namespace std;
int k,n;
long long line[MAX];
long long ans;
void binary_search(long long start, long long end, int n){
    while(start<=end){
        int sum=0;
        long long mid=(start+end)/2;
        for(int i=0;i<k;i++) sum+=line[i]/mid;
        if(sum<n) end=mid-1;
        else{
            ans=mid;
            start=mid+1;
        }
    }
}
int main(){
    scanf("%d %d",&k,&n);
    long long start=1, end=0;
    for(int i=0;i<k;i++){
        scanf("%lld",&line[i]);
        end=max(end,line[i]);
    }
    binary_search(start, end, n);
    printf("%lld",ans);
}