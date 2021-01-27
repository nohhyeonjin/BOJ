#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int arr[500000];
int result[500000];
void merge(int left, int right){
    int mid=(left+right)/2;
   
    int i=left;
    int j=mid+1;
    int k=left;
    
    while(i<=mid&&j<=right){
        if(arr[i]<=arr[j]){
            result[k]=arr[i];
            i++;
        }else{
            result[k]=arr[j];
            ans+=(long long)mid-i+1;
            j++;
        }
        k++;
    }
    while(i<=mid){
        result[k]=arr[i];
        i++;k++;
    }
    while(j<=right){
        result[k]=arr[j];
        j++;k++;
    }
    for(int i=left;i<=right;i++) arr[i]=result[i];
}
void partition(int left, int right){
    if(left==right) return;
    int mid=(left+right)/2;
    
    partition(left,mid);
    partition(mid+1,right);
    merge(left,right);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    partition(0,n-1);
    printf("%lld",ans);
}