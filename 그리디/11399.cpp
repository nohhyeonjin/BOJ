#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        int p;
        scanf("%d",&p);
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        sum+=v[i]*(n-i);
    }
    printf("%d",sum);
}