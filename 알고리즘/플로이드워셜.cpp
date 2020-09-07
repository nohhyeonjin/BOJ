#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int graph[101][101];
int main(){
    int v,e;
    //vertex 개수, edget 개수
    cin >> v >> e;
    
    //최단거리테이블 초기화
    for(int i=0;i<101;i++) fill(graph[i],graph[i]+101,INF);
    
    //자기자신으로 가는 비용은 0으로 초기화
    for(int i=1;i<=v;i++) graph[i][i]=0;
    
    //edge 정보 입력받기
    for(int i=0;i<e;i++){
        int a,b,c;
        //a vertex에서 b vertex로 가는 비용 c
        cin >> a >> b >> c;
        graph[a][b]=c;
    }

    //플로이드 워셜
    for(int k=1; k<=v; k++) {
        for(int a=1; a<=v; a++) {
            for(int b=1; b<=v; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    //출력
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(graph[i][j]==INF) cout << "INF" << "\n";
            else cout << graph[i][j] << "\n";
        }
    }
}