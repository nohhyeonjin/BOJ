#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int s[13];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    while(1){
        int k;
        cin >> k;
        if(k==0) break;
        for(int i=0;i<k;i++) cin >> s[i];
        vector<int> binary(k);
        fill(binary.end()-6,binary.end(),1);
        vector<vector<int>> ans;
        do{
            vector<int> v;
            for(int i=0;i<k;i++){
                if(binary[i]==1) v.push_back(s[i]);
            }
            ans.push_back(v);
        }while(next_permutation(binary.begin(),binary.end()));
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            vector<int> cur=ans[i];
            for(int j=0;j<6;j++) cout << cur[j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }
}