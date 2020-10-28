#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[5];
    for(int i=0;i<5;i++) scanf("%d",&arr[i]);
    while(1){
        bool flag=true;
        for(int i=0;i<5;i++){
            if(arr[i]!=i+1){
                flag=false;
                break;
            }
        }
        if(flag) break;
        for(int i=0;i<4;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                for(int j=0;j<5;j++) printf("%d ",arr[j]);
                printf("\n");
            }
        }
    }
}