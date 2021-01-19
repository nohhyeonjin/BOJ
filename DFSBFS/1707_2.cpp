#include <bits/stdc++.h>
using namespace std;
int v,e;
vector<int> graph[20001];
int visited[20001];
int group[20001];
bool flag;
void dfs(int vNum, int g){
    visited[vNum]=1;
    int gnum;
    if(g==1) gnum=2;
    if(g==2) gnum=1;
    group[vNum]=gnum;
    for(int i=0;i<graph[vNum].size();i++){
        if(group[graph[vNum][i]]!=0&&group[graph[vNum][i]]==gnum){
            flag=false;
            return;
        }
    }
    for(int i=0;i<graph[vNum].size();i++){
        if(visited[graph[vNum][i]]==0) dfs(graph[vNum][i],gnum);
    }    
}
int main(){
    int k;
    scanf("%d",&k);
    while(k--){
        flag=true;
        scanf("%d %d",&v,&e);
        for(int i=1;i<20001;i++) graph[i].clear();
        memset(visited,0,sizeof(visited));
        memset(group,0,sizeof(group));
        for(int i=0;i<e;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=v;i++){
            if(visited[i]==0) dfs(i,2);
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}