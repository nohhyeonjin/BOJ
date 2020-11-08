#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
int n,m;
int arr[MAX];
bool binary_search(int start, int end, int target){
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==target) return true;
        if(target<arr[mid]) end=mid-1;
        if(arr[mid]<target) start=mid+1; 
    }
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int target;
        scanf("%d",&target);
        printf("%d\n",binary_search(0,n-1,target)?1:0);
    }
}