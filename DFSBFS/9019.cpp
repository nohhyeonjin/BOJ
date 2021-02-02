#include <bits/stdc++.h>
using namespace std;
bool visited[10000];
string bfs(int a, int b){
    queue<pair<int,string>> q;
    q.push({a,""});
    visited[a]=true;
    while(!q.empty()){
        int num=q.front().first;
        string order=q.front().second;
        q.pop();
        if(num==b) return order;
        //D
        int tmpNum=(num*2)%10000;
        if(!visited[tmpNum]){
            q.push({tmpNum,order+"D"});
            visited[tmpNum]=true;
        }
        //S
        tmpNum=(num-1>=0)?num-1:9999;
        if(!visited[tmpNum]){
            q.push({tmpNum,order+"S"});
            visited[tmpNum]=true;
        }
        //L
        tmpNum=(num%1000)*10+num/1000;
        if(!visited[tmpNum]){
            q.push({tmpNum,order+"L"});
            visited[tmpNum]=true;
        }
        //R
        tmpNum=(num%10)*1000+(num/10);
        if(!visited[tmpNum]){
            q.push({tmpNum,order+"R"});
            visited[tmpNum]=true;
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        memset(visited,0,sizeof(visited));
        cout << bfs(a,b) << "\n";
    }
}