#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        v.push_back(num);
    } 
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) printf("%d\n",v[i]);
}