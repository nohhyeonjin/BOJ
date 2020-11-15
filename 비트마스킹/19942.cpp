#include <bits/stdc++.h>
#define MAX 15
using namespace std;
int n;
int mp,mf,ms,mv;
int minCost=1e9;
int p[MAX],f[MAX],s[MAX],v[MAX],c[MAX];
int main(){
    scanf("%d",&n);
    scanf("%d %d %d %d",&mp,&mf,&ms,&mv);
    for(int i=0;i<n;i++) scanf("%d %d %d %d %d",&p[i],&f[i],&s[i],&v[i],&c[i]);
    vector<vector<int>> ans;
    for(int i=1;i<(1<<n);i++){
        vector<int> tmp;
        int sp=0,sf=0,ss=0,sv=0,sc=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sp+=p[j];
                sf+=f[j];
                ss+=s[j];
                sv+=v[j];
                sc+=c[j];
                tmp.push_back(j+1);
            }
        }       
        if(!(sp>=mp&&sf>=mf&&ss>=ms&&sv>=mv)) continue;
        if(sc==minCost) ans.push_back(tmp);
        if(sc<minCost){
            minCost=sc;
            ans.clear();
            ans.push_back(tmp);
        }
    }
    if(minCost==1e9) printf("-1");
    else{
        printf("%d\n",minCost);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans[0].size();i++) printf("%d ",ans[0][i]);
    }
}