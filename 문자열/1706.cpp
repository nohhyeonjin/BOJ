#include <bits/stdc++.h>
using namespace std;
string s[20];
vector<string> vec;
int main(){
    int r, c;
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++) cin >> s[i];
    for(int i=0;i<r;i++){
        string tmp="";
        for(int j=0;j<c;j++){
            if(s[i][j]=='#'){
                if(tmp.size()>1) vec.push_back(tmp);
                tmp="";
            }else if(j==c-1){
                tmp+=s[i][j];
                if(tmp.size()>1) vec.push_back(tmp);
            }else tmp+=s[i][j];
        }
    }
    for(int i=0;i<c;i++){
        string tmp="";
        for(int j=0;j<r;j++){
            if(s[j][i]=='#'){
                if(tmp.size()>1) vec.push_back(tmp);
                tmp="";
            }else if(j==r-1){
                tmp+=s[j][i];
                if(tmp.size()>1) vec.push_back(tmp);
            }else tmp+=s[j][i];
        }
    }
    sort(vec.begin(),vec.end());
    cout << vec[0];
}