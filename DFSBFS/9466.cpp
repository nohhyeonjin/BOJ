#include <bits/stdc++.h>
using namespace std;
int visited[100001];
int done[100001];
int num[100001];
int cnt;
void dfs(int cur){
    visited[cur]=1;
    int next=num[cur];
    if(visited[next]==0) dfs(next); //방문안했을경우
    else if(done[next]==0){   //방문했지만 사이클체크안했을경우 
        //사이클에 해당하는 학생 수 세기
        for(int i=next;i!=cur;i=num[i]) cnt++;
        cnt++;
    }
    done[cur]=1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        memset(num,0,sizeof(int)*100001);
        memset(visited,0,sizeof(int)*100001);
        memset(done,0,sizeof(int)*100001);
        cnt=0;
        for(int i=1;i<=n;i++) scanf("%d",&num[i]);
        for(int i=1;i<=n;i++){
            if(visited[i]==0) dfs(i);
        }
        printf("%d\n",n-cnt);
    }
}