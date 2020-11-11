#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long budget[10000];
long long ans;
void binary_search(long long start, long long end){
    while(start<=end){
        int sum=0;
        long long mid=(start+end)/2;
        for(int i=0;i<n;i++){
            if(budget[i]<=mid) sum+=budget[i];
            else sum+=mid;
        }
        if(sum>m) end=mid-1;
        else{
            ans=mid;
            start=mid+1;
        }
    }

}
int main(){
    scanf("%d",&n);
    long long total=0;
    long long maxVal=0;
    for(int i=0;i<n;i++){
        scanf("%d",&budget[i]);
        total+=budget[i];
        maxVal=max(maxVal,budget[i]);
    }
    scanf("%lld",&m);
    if(total<=m){
        printf("%lld",maxVal);
    }
    else{    
        binary_search(0,m);
        printf("%lld",ans);
    }
}