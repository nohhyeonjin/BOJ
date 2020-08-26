#include <bits/stdc++.h>
using namespace std;
int n,k,s,x,y;
int arr[201][201];
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
class virus{
public:
    int val;
    int sec;
    pair<int,int> pos;
    virus(int val, int sec, pair<int,int> pos){
        this->val=val;
        this->sec=sec;
        this->pos=pos;
    }
    bool operator <(virus& other){
        return this->val<other.val;
    }
};
vector<virus> v;
queue<virus> q;
void dfs(){
    while(!q.empty()){
        virus cur=q.front();
        if(cur.sec==s) return;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=dy[i]+cur.pos.first;
            int nx=dx[i]+cur.pos.second;
            if(ny>0&&ny<=n&&nx>0&&nx<=n){
                if(arr[ny][nx]==0){    
                    arr[ny][nx]=cur.val;
                    q.push(virus(arr[ny][nx],cur.sec+1,make_pair(ny,nx)));
                }
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0) v.push_back(virus(arr[i][j],0,make_pair(i,j)));
        }
    }
    scanf("%d %d %d",&s,&x,&y);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) q.push(v[i]);
    dfs();
    printf("%d",arr[x][y]);
}