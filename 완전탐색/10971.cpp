#include <bits/stdc++.h>
using namespace std;
int n;
int ans=1e9;
int w[10][10];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&w[i][j]);
    }
    vector<int> v;
    for(int i=0;i<n;i++) v.push_back(i);
    do{
        vector<int> tmp;
        for(int i=0;i<n;i++) tmp.push_back(v[i]);
        tmp.push_back(v[0]);

        int sum=0;
        bool flag=true;
        for(int i=0;i<tmp.size()-1;i++){
            int start=tmp[i];
            int end=tmp[i+1];
            if(w[start][end]==0){
                flag=false;
                break;
            }
            sum+=w[start][end];
        }
        if(flag) ans=min(ans,sum);
    }while(next_permutation(v.begin(),v.end()));
    printf("%d",ans);
}