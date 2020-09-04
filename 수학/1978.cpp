#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int arr[1001];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        v.push_back(num);
    }
    //에라토스테네스의 체
    for(int i=2;i<1001;i++) arr[i]=i;
    for(int i=2;i<1001;i++){
        if(arr[i]==0) continue;
        for(int j=i*2;j<1001;j+=i) arr[j]=0;
    }
    int ans=0;
    for(int i=0;i<v.size();i++){
        int cur=v[i];
        if(arr[cur]!=0) ans++;
    }
    printf("%d",ans);
}