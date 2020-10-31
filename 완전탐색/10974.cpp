#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> arr;
    for(int i=1;i<=n;i++) arr.push_back(i);
    do{
        for(int i=0;i<n;i++) printf("%d ",arr[i]);
        printf("\n");
    }while(next_permutation(arr.begin(),arr.end()));
}