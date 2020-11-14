#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int v,e,start;
vector<pair<int,int>> edges[101];   //a->{b,c}
int table[101];
bool bellmanford(int start){
    table[start]=0;
    //vertex 개수만큼 반복
    for(int i=0;i<v;i++){
        //모든 edge확인
        for(int cur=1;cur<=v;cur++){
            for(int j=0;j<edges[cur].size();j++){
                int next=edges[cur][j].first;
                int cost=edges[cur][j].second;
                //현재 edge를 거쳐 다른 vertex로 이동하는 거리가 더 짧다면 갱신
                if(table[cur]!=INF&&table[next]>table[cur]+cost){
                    table[next]=table[cur]+cost;
                    //n번째에서도 테이블 갱신 시 음수 사이클 존재
                    if(i==v-1) return true;
                }
            }
        }
    }
    return false;
}
int main(){
    //vertex개수, edge개수, 시작점
    cin >> v >> e >> start; 
    //edge 정보 입력받기
    for(int i=0;i<e;i++){
        int a,b,c;
        //a vertex에서 b vertex로 가는 비용 c
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b,c));
    }
    fill(table,table+101,INF);
    bool negativeCycle=bellmanford(start);
    if(negativeCycle) printf("-1");
    else{
        for(int i=1;i<=v;i++){
            if(table[i]==INF) cout << "INF" << "\n";
            else cout << table[i] << "\n";
        }
    }
}