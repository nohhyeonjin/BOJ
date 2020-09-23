#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> v;
int main(){
    int colMax=0;
    for(int i=0;i<5;i++){
        char c;
        int cnt=0;
        vector<char> row;
        while(1){
            scanf("%c",&c);
            if(c=='\n') break;
            row.push_back(c);
            cnt++;
        }
        colMax=max(colMax,cnt);
        v.push_back(row);
    }
    for(int i=0;i<colMax;i++){
        for(int j=0;j<5;j++){
            if(v[j].size()>i) printf("%c",v[j][i]);
        }
    }

}