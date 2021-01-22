#include <bits/stdc++.h>
using namespace std;
int n,m;
int card[500000];
int have[500000];
void binarySearch(int start, int end, int target){
    bool flag=false;
    while(start<=end){
        int mid=(start+end)/2;
        if(have[mid]==target){
            flag=true;
            break;
        }else if(have[mid]>target) end=mid-1;
        else start=mid+1;
    }
    printf("%d ",flag?1:0);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&have[i]);
    sort(have,have+n);
    scanf("%d",&m);
    for(int i=0;i<m;i++) scanf("%d",&card[i]);
    for(int i=0;i<m;i++) binarySearch(0,n-1, card[i]);
}