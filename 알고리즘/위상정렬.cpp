#include <bits/stdc++.h>
#define MAX 101
using namespace std;
int v,e;    //vertex 개수, edge 개수
int inDegree[MAX];  //진입차수
vector<int> graph[MAX];
void topologySort(){
    vector<int> result;
    queue<int> q;
    //진입차수 0인 vertex들 큐에 삽입
    for(int i=1;i<=v;i++){
        if(inDegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        int cur=q.front();
        result.push_back(cur);
        q.pop();
        //cur와 연결된 vertex들의 진입차수 -1 후 0일경우 큐에 삽입
        for(int i=0;i<graph[cur].size();i++){
            inDegree[graph[cur][i]]--;
            if(inDegree[graph[cur][i]]==0) q.push(graph[cur][i]);
        }
    }
    //출력
    for(int i=0;i<result.size();i++) printf("%d ",result[i]);
    
}
int main(){
    scanf("%d %d",&v,&e);
    for(int i=0;i<e;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);  //vertex a->vectex b
        inDegree[b]++;
    }
    topologySort();
}