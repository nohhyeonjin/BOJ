#include <bits/stdc++.h>
#define MAX 1004000
using namespace std;
int n;
int arr[MAX];
int main(){
    scanf("%d",&n);
    for(int i=2;i<MAX;i++) arr[i]=i;
    for(int i=2;i<MAX;i++){
        if(arr[i]==0) continue;
        for(int j=i*2;j<MAX;j+=i) arr[j]=0;
    }
    for(int i=n;;i++){
        int num=arr[i];
        if(num==0) continue;
        string s=to_string(num);
        string ns="";
        for(int j=s.size()-1;j>=0;j--){
            ns+=s[j];
        }
        if(s==ns){
            cout << s;
            break;
        }
    }
}