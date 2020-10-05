#include <bits/stdc++.h>
using namespace std;
int arr[10]={8,2,4,9,1,3,0,5,7,6};
int main(){
    for(int i=0;i<10;i++){
        int minIdx=i;
        for(int j=i+1;j<10;j++){
            if(arr[minIdx]>arr[j]) minIdx=j;
        }
        swap(arr[i],arr[minIdx]);   //첫번째 자리에 가장 작은거 넣기(자리는 정해져있음)
    }
    for(int i=0;i<10;i++) printf("%d ",arr[i]);
}