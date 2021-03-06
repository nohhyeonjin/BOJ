#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int low,high;
long long result;
int price[100000];
void binarySearch(int left, int right){
    if(left>right) return;
    long long mid=(left+right)/2;
    int cnt=1;
    int sum=mid;
    for(int i=0;i<n;i++){
        int cur=price[i];
        if(sum-cur<0){
            cnt++;
            sum=mid;
        }
        sum-=cur;
    }
    if(cnt<=m){
        result=mid;
        binarySearch(left,mid-1);
    }else binarySearch(mid+1,right);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&price[i]);
        low=max(low,price[i]);
        high+=price[i];
    }
    binarySearch(low,high);
    printf("%lld",result);
}