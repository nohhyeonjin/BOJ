#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    long long arr[100000];
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    sort(arr,arr+n);
    long long prev=arr[0];
    int cnt=1;
    int maxCnt=0;
    long long ans=prev;
    for(int i=1;i<n;i++){
        long long cur=arr[i];
        if(prev==cur) cnt++;
        if(prev!=cur||i==n-1){
            if(cnt>maxCnt){
                maxCnt=cnt;
                ans=prev;
            }
            cnt=1;
        }
        prev=cur;
    }
    printf("%lld",ans);
}