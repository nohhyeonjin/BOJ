#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> g1[2001];
int g2[2001][2001];
vector<pair<int,int>> g3;
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g1[a].push_back(b);
        g1[b].push_back(a);
        g2[a][b]=g2[b][a]=1;
        g3.push_back({a,b});
        g3.push_back({b,a});
    }
    bool find=false;
    for(int i=0;i<m*2;i++){
        for(int j=0;j<m*2;j++){
            int a=g3[i].first;
            int b=g3[i].second;
            int c=g3[j].first;
            int d=g3[j].second;
            if(a==b||a==c||a==d||b==c||b==d||c==d) continue;
            if(g2[b][c]==0) continue;
            for(int k=0;k<g1[d].size();k++){
                int e=g1[d][k];
                if(e!=a&&e!=b&&e!=c&&e!=d){
                    find=true;
                    break;
                }
            }
            if(find) break;
        }
        if(find) break;
    }
    if(find) cout << 1;
    else cout << 0;
}