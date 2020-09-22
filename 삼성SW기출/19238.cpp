#include <bits/stdc++.h>
using namespace std;
int n, m;
long long fuel;
int area[21][21], disTable[21][21], visited[21][21];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
pair<int,int> taxiPos;  //(y,x)
vector<pair<pair<int,int>,pair<int,int>>> customer; //출발(y,x) 도착(y,x)
vector<int> chk;
void input(){
    scanf("%d %d %d",&n,&m,&fuel);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) scanf("%d",&area[i][j]);
    }
    int y,x;
    scanf("%d %d",&y,&x);
    taxiPos={y,x};
    for(int i=0;i<m;i++){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        customer.push_back({{a,b},{c,d}});
    }
    chk.resize(m);
}
bool inside(int ny, int nx){
    if(ny>0&&nx>0&&ny<=n&&nx<=n) return true;
    return false;
}
void cal_disTable(int y, int x){    //(y,x)가 출발지인 거리테이블 계산
    //초기화
    for(int i=0;i<21;i++){
        memset(visited[i],0,sizeof(int)*21);
        memset(disTable[i],0,sizeof(int)*21);
    }
    //bfs
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=1;
    disTable[y][x]=0;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        int dis=disTable[y][x];
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(inside(ny,nx)&&visited[ny][nx]==0&&area[ny][nx]!=1){
                q.push({ny,nx});
                visited[ny][nx]=1;
                disTable[ny][nx]=dis+1;
            }
        }
    }
}
bool can_go(int y, int x, int dis){
    if((dis==0)&&!((y==taxiPos.first)&&(x==taxiPos.second))) return false;
    return true;
}
int choose_customer(){
    //최단거리계산
    int minDis=1e9;
    for(int i=0;i<m;i++){
        int y=customer[i].first.first;
        int x=customer[i].first.second;
        int dis=disTable[y][x]; 
        //못가는경우 제외
        if(!can_go(y,x,dis)) continue;
        //탄적없는 승객일경우
        if(chk[i]==0) minDis=min(minDis,dis);
    }
    //어떤 승객도 못갈경우
    if(minDis==1e9) return -1;

    //최단거리에 있는 승객 확인
    vector<pair<pair<int,int>,int>> minDisCus;
    for(int i=0;i<m;i++){
        int y=customer[i].first.first;
        int x=customer[i].first.second;
        int dis=disTable[y][x];    
        //못가는경우 제외
        if(!can_go(y,x,dis)) continue;
        if((chk[i]==0)&&(dis==minDis)) minDisCus.push_back({{y,x},i});
    }
    sort(minDisCus.begin(),minDisCus.end());
    
    return minDisCus[0].second; //고른 승객의 인덱스 반환
}
bool solution(){
    for(int i=0;i<m;i++){
        //현재 택시위치에서 최단거리 테이블 구하기
        cal_disTable(taxiPos.first, taxiPos.second);
      
        //손님 선택 후 태우러감
        int cusIdx=choose_customer();
        if(cusIdx==-1) return false;
        chk[cusIdx]=1;
        int cusY=customer[cusIdx].first.first;
        int cusX=customer[cusIdx].first.second;
        fuel-=disTable[cusY][cusX];
        taxiPos={cusY,cusX};
        if(fuel<=0) return false;
      
        //현재 택시위치에서 최단거리 테이블 구하기
        cal_disTable(taxiPos.first, taxiPos.second);
      
        //손님 목적지로 이동시킴
        int destiY=customer[cusIdx].second.first;
        int destiX=customer[cusIdx].second.second;
        int destiDis=disTable[destiY][destiX];
        if(!can_go(destiY,destiX,destiDis)) return false;
        fuel-=destiDis;
        if(fuel<0) return false;
        fuel+=(destiDis*2);
        if(fuel<=0) return false;
        taxiPos={destiY,destiX};
    }
    return true;
}
int main(){
    input();
    bool result=solution();
    if(result) printf("%lld",fuel);
    else printf("-1");
}