#include <bits/stdc++.h>
using namespace std;
int arr[15]={8,2,4,9,1,3,0,5,7,6,1,5,5,9,2};
int temp[15];
void merge(int left, int right){
    int mid=(left+right)/2;
    
    int i=left;	//첫번째배열 시작 인덱스
    int j=mid+1;	//두번째배열 시작 인덱스
    int k=left;	//임시배열 시작 인덱스
    
    while(i<=mid&&j<=right){	//두 배열이 끝에 이를때까지 반복
        if(arr[i]<=arr[j]){	//첫번째배열 원소가 두번째배열 원소보다 작으면
            temp[k]=arr[i];	//임시배열에 첫번째 원소 추가
            i++;	//첫번째배열 인덱스++
        }else{
            temp[k]=arr[j];
            j++;
        }
        k++;	//임시배열 인덱스++
    }
    //남은 데이터 
    while(i<=mid){ 
        temp[k]=arr[i];
        i++; k++;
    }
    while(j<=right){
        temp[k]=arr[j];
        j++; k++;
    }
    //원본배열을 임시배열로 덮어쓰기
    for(int i=left;i<=right;i++) arr[i]=temp[i];
}
void partition(int left, int right){
    if(left==right) return;
    int mid=(left+right)/2;
    
    partition(left,mid);
    partition(mid+1,right);
    merge(left,right);
}
int main(){
    partition(0,14);
    for(int i=0;i<15;i++) printf("%d ",arr[i]);
}