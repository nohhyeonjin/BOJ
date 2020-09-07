#include <bits/stdc++.h>
using namespace std;
int binarySearch_rec(vector<int> v, int start, int end, int target){
    if(start>end) return -1;
    int mid=(start+end)/2;
    if(v[mid]==target) return mid;
    //mid가 target보다 오른쪽에 있으면
    else if(v[mid]>target) return binarySearch_rec(v,start,mid-1,target);
    //mid가 target보다 왼쪽에 있으면
    else return binarySearch_rec(v,mid+1,end,target);
}
int binarySearch_loop(vector<int> v, int start, int end, int target){
    while(start<=end){
        int mid=(start+end)/2;
        if(v[mid]==target) return mid;
        //mid가 target보다 오른쪽에 있으면
        else if(v[mid]>target) end=mid-1;
        //mid가 target보다 왼쪽에 있으면
        else start=mid+1;
    }
}
int main(){
    vector<int> v={1,3,4,8,9,10,11,12,14,15};
    int result=binarySearch_loop(v,0,v.size()-1,14);
    printf("%d",result);
}