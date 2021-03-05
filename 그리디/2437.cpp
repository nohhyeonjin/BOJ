#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[10001];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n);
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+1<arr[i]) break;
        sum+=arr[i];
    }
    printf("%d",sum+1);
}