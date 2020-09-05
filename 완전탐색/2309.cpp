#include <bits/stdc++.h>
using namespace std;
int h[9];
int main(){
    for(int i=0;i<9;i++) scanf("%d",&h[i]);
    vector<bool> binary(9);
    fill(binary.end()-7,binary.end(),1);
    do{
        int sum=0;
        for(int i=0;i<9;i++){
            if(binary[i]==1){
                sum+=h[i];
            }
        }
        if(sum==100){
            vector<int> ans;
            for(int i=0;i<9;i++){
                if(binary[i]==1) ans.push_back(h[i]);
            }
            sort(ans.begin(),ans.end());
            for(int i=0;i<7;i++) printf("%d\n",ans[i]);
            break;
        }
    }while(next_permutation(binary.begin(),binary.end()));
}