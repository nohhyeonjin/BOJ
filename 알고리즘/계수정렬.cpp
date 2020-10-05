#include <bits/stdc++.h>
using namespace std;
int arr[15]={8,2,4,9,1,3,0,5,7,6,1,5,5,9,2};
int cnt[15];
int main(){
    for(int i=0;i<15;i++) cnt[arr[i]]++;
    for(int i=0;i<15;i++){
        for(int j=0;j<cnt[i];j++) printf("%d ",i);
    }
}