#include <iostream>
#include <algorithm>
using namespace std;
int n;
int ans;
int arr[8];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    do{
        int sum=0;
        for(int i=0;i<n-1;i++){
            int a=arr[i];
            int b=arr[i+1];
            sum+=abs(a-b);
        }
        if(sum>ans) ans=sum;
    }while(next_permutation(arr,arr+n));
    cout << ans;
}