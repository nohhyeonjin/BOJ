#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
long long n,m;
long long height[MAX];
long long ans;
void binary_search(long long start, long long end, long long target){
    while(start<=end){
        long long sum=0;
        long long mid=(start+end)/2;
        for(int i=0;i<n;i++) if(height[i]>mid) sum+=height[i]-mid;
        if(sum<target) end=mid-1;
        else{
            ans=mid;
            start=mid+1;
        }
    }
}
int main(){
    scanf("%lld %lld",&n,&m);
    long long start=0, end=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&height[i]);
        end=max(end,height[i]);
    }
    binary_search(start,end,m);
    printf("%lld",ans);
}