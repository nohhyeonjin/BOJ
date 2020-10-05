#include <bits/stdc++.h>
using namespace std;
int arr[10]={8,2,4,9,1,3,0,5,7,6};
void quickSort(int* arr,int s,int e){
    if(s>=e) return;
    int pivot=s;
    int left=s+1;
    int right=e;
    while(left<=right){
        //피봇보다 큰 원소 찾기
        while(left<=e&&arr[left]<=arr[pivot]) left++;
        //피봇보다 작은 원소 찾기
        while(right>s&&arr[right]>=arr[pivot]) right--;
        //엇갈리면 피봇과 작은원소 교체
        if(left>right) swap(arr[pivot],arr[right]);
        //아니면 작은 원소와 큰 원소 교체
        else swap(arr[left],arr[right]);
    }
    //분할(왼쪽 오른쪽 각각 정렬 수행)
    quickSort(arr,s,right-1);
    quickSort(arr,right+1,e);
}
int main(){
    quickSort(arr,0,9);
    for(int i=0;i<10;i++) printf("%d ",arr[i]);
}