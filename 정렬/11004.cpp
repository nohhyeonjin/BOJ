#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        v.push_back({num});
    }
    sort(v.begin(),v.end());
    printf("%d",v[k-1]);
}