#include <bits/stdc++.h>
#define MAX 501
using namespace std;
int n, m, grades[MAX];
int graph[MAX][MAX];
vector<pair<int,int>> dif;
int inDegree[MAX]; 
void topology(){
    vector<int> result;
    queue<int> q;
    bool certain=true;
    for(int i=1;i<=n;i++) if(inDegree[i]==0) q.push(i);
    while(!q.empty()){
        if(q.size()>1){
            certain=false;
            break;
        }
        int cur=q.front();
        result.push_back(cur);
        q.pop();
        for(int i=1;i<=n;i++){
            if(graph[cur][i]==1){
                inDegree[i]--;
                if(inDegree[i]==0) q.push(i);
            }
        }
    }
    if(certain==false) printf("?\n");
    else if(result.size()!=n) printf("IMPOSSIBLE\n");
    else{
        for(int i=0;i<n;i++) printf("%d ",result[i]);
        printf("\n");
    }
}               
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        //초기화
        for(int i=0;i<MAX;i++) memset(graph[i],0,sizeof(int)*MAX);
        memset(grades,0,sizeof(int)*MAX);
        memset(inDegree,0,sizeof(int)*MAX);
        dif.clear();
        //입력
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&grades[i]);
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            int a, b;
            scanf("%d %d",&a,&b);
            dif.push_back({a,b});
        }
        //선긋기
        for(int i=1;i<=n;i++){
            int start=grades[i];
            for(int j=i+1;j<=n;j++){
                int end=grades[j];
                graph[start][end]=1;
                inDegree[end]++;
            }
        }
        for(int i=0;i<dif.size();i++){
            int a=dif[i].first, b=dif[i].second;
            if(graph[a][b]==1){
                graph[b][a]=1; graph[a][b]=0;
                inDegree[a]++; inDegree[b]--;
            }else{
                graph[a][b]=1; graph[b][a]=0;
                inDegree[b]++; inDegree[a]--;
            }
        }
        topology();
    }
}