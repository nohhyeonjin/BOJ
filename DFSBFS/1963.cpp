#include <bits/stdc++.h>
using namespace std;
int prime[10000];
bool visited[10000];
bool isPrime(int num){
    if(prime[num]==0) return false;
    return true;
}
int bfs(int a, int b){
    queue<pair<int,int>> q; //{숫자,최소회수}
    q.push({a,0});
    visited[a]=true;
    while(!q.empty()){
        int num=q.front().first;
        int cnt=q.front().second;
        q.pop();
        if(num==b) return cnt;
        for(int i=0;i<4;i++){
            string tmp=to_string(num);
            for(int j=0;j<10;j++){
                if(i==0&&j==0) continue;
                if(tmp[i]==j) continue;
                tmp[i]=j+'0';
                if(isPrime(stoi(tmp))&&!visited[stoi(tmp)]){
                    q.push({stoi(tmp),cnt+1});
                    visited[stoi(tmp)]=true;
                }
            }
        }
    }
    return -1;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for(int i=2;i<10000;i++) prime[i]=i;
    for(int i=2;i<10000;i++){
        if(prime[i]==0) continue;
        for(int j=i*2;j<10000;j+=i){
            prime[j]=0;
        }
    }
    while(t--){
        int a,b;
        cin >> a >> b;
        memset(visited,0,sizeof(visited));
        int ans=bfs(a,b);
        if(ans==-1) cout << "Impossible" << "\n";
        else cout << ans << "\n";
    }
}