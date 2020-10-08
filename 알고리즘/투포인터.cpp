#include <bits/stdc++.h>
#define MAX 5
using namespace std;
int m;
int arr[MAX];
int main(){
    scanf("%d",&m);
    for(int i=0;i<MAX;i++) scanf("%d",&arr[i]);
    int cnt=0;
    int sum=0;
    int end=0;
    for(int start=0;start<MAX;start++){
        //sum이 m보다 작으면 end 증가
        while(end<MAX&&sum<m){
            sum+=arr[end];
            end++;
        }
        //sum이 m과 같으면 cnt 증가
        if(sum==m) cnt++;
        //sum이 m과 같거나 크면 start 증가
        sum-=arr[start];
    }
    printf("%d",cnt);
}