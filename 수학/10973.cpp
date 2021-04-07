#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[10000];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    if(prev_permutation(arr,arr+n)){
        for(int i=0;i<n;i++) cout << arr[i] << " ";
    }else cout << "-1";
}