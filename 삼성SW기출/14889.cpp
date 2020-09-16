#include <bits/stdc++.h>
using namespace std;
int n;
int num[20][20];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&num[i][j]);
    }
    vector<int> binary(n);
    fill(binary.end()-n/2,binary.end(),1);
    int ans=1e9;
    do{
        vector<int> s,l;
        for(int i=0;i<n;i++){
            if(binary[i]==1) s.push_back(i);
            if(binary[i]==0) l.push_back(i);
        }
        int sScore=0,lScore=0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                sScore+=num[s[i]][s[j]];
                lScore+=num[l[i]][l[j]];
            }
        }
        ans=min(ans,abs(sScore-lScore));
    }while(next_permutation(binary.begin(),binary.end()));
    printf("%d",ans);
}