#include <iostream>
using namespace std;
int n;
int num[1000000];
int tmp[1000000];
void merge(int left, int right){
    int mid=(left+right)/2;
    int i=left;
    int j=mid+1;
    int k=left;
    while(i<=mid&&j<=right){
        if(num[i]<num[j]) tmp[k++]=num[i++];
        else tmp[k++]=num[j++];
    }
    while(i<=mid) tmp[k++]=num[i++];
    while(j<=right) tmp[k++]=num[j++];
    for(int i=left;i<=right;i++) num[i]=tmp[i];
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
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    partition(0,n-1);
    for(int i=0;i<n;i++) printf("%d\n",num[i]);
}