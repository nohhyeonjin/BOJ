#include <bits/stdc++.h>
using namespace std;
vector<int> p,m;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        if(num>0) p.push_back(num);
        else m.push_back(num);
    }
    sort(p.begin(),p.end(),greater<int>());
    sort(m.begin(),m.end());
    for(int i=0;i<m.size();i++) p.push_back(m[i]);
    int sum=0, idx=0;
    while(idx<n){
        if( (n-idx>=2) && ((p[idx]>1&&p[idx+1]>1)||(p[idx]<0&&p[idx+1]<=0)) ){
            sum+=p[idx]*p[idx+1];
            idx+=2;
        }
        else{
            sum+=p[idx];
            idx++;
        }
    }
    printf("%d",sum);
}