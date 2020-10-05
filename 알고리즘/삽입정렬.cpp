#include <bits/stdc++.h>
using namespace std;
int arr[10]={8,2,4,9,1,3,0,5,7,6};
//선택된 값보다 앞에 있는 원소들과 비교
int main(){
    for(int i=1;i<10;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]) swap(arr[j],arr[j-1]);
            else break; //자기보다 작은 원소만나면 중단
        }
    }
    for(int i=0;i<10;i++) printf("%d ",arr[i]);
}