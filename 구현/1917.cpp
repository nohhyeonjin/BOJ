#include <iostream>
#include <vector>
using namespace std;
int paper[6][6];
vector<vector<string>> cubes = {
    {"0010",
     "1111",
     "0010"},
    {"0100",
     "1111",
     "1000"},
    {"0010",
     "1111",
     "0100"},
    {"0001",
     "1111",
     "1000"},
    {"0001",
     "1111",
     "0100"},
    {"11100",
     "00111"},
    {"1100",
     "0111",
     "0010"},
    {"1100",
     "0111",
     "0001"},
    {"0010",
     "1110",
     "0011"},
    {"0001",
     "1111",
     "0001"},
    {"1100",
     "0110",
     "0011"}
};
vector<string> mirror(vector<string> v){
    vector<string> ans;
    int h=v.size();
    int w=v[0].size();
    for(int i=0;i<h;i++){
        string s;
        for(int j=w-1;j>=0;j--) s+=v[i][j];
        ans.push_back(s);
    }
    return ans;
}
vector<string> rotate(vector<string> v){
    vector<string> ans;
    int h=v.size();
    int w=v[0].size();
    for(int i=0;i<w;i++){
        string s;
        for(int j=h-1;j>=0;j--) s+=v[j][i];
        ans.push_back(s);
    }
    return ans;
}
bool check(int y, int x, vector<string> cube){
    int h=cube.size();
    int w=cube[0].size();
    if(y+h>6||x+w>6) return false;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(paper[y+i][x+j]==1){
                if(cube[i][j]=='0') return false;
            }
            if(paper[y+i][x+j]==0){
                if(cube[i][j]=='1') return false;
            }
        }
    }
    return true;
}
int main(){
    int t=3;
    while(t--){
        bool ans=false;
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++) scanf("%d",&paper[i][j]);
        }
        for(int k=0;k<11;k++){
            vector<string> cube=cubes[k];
            for(int i=0;i<4;i++){
                cube=rotate(cube);
                for(int j=0;j<2;j++){
                    cube=mirror(cube);
                    for(int y=0;y<6;y++){
                        for(int x=0;x<6;x++){
                            ans|=check(y,x,cube);
                        }
                    }
                }
            }
        }
        printf(ans?"yes\n":"no\n");
    }
}