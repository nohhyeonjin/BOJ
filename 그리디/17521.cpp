#include <bits/stdc++.h>
using namespace std;
int n;
long long w;
int graph[16];
int chk[16];
long long coin;
vector<int> dirArr, idxArr;
void buy(int cur){
    coin=coin+w/cur;
    w=w%cur;
}
void sell(int cur){
    w=w+coin*cur;
    coin=0;
}
int main(){
    scanf("%d %d",&n,&w);
    for(int i=1;i<=n;i++) scanf("%d",&graph[i]);
    int cur, next;
    int prevDir, dir;
    for(int i=1;i<=n-1;i++){
        cur=graph[i];
        next=graph[i+1];
        if(cur==next) dir=0;
        if(cur<next) dir=1;
        if(cur>next) dir=2;
        //방향이 바뀌는 순간 기록
        if(i==1||prevDir!=dir){
            prevDir=dir;
            dirArr.push_back(dir);
            idxArr.push_back(i);
        }
    }
    int start;
    for(int i=0;i<dirArr.size();i++){
        if(dirArr[i]==1){
            start=i;
            break;
        }
    }
    for(int i=start;i<dirArr.size();i++){
        int dir=dirArr[i];
        int idx=idxArr[i];
        if(dir==1) buy(graph[idx]);
        if(dir==2) sell(graph[idx]);
    }
    sell(graph[n]);
    printf("%lld",w);
}