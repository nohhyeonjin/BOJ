#include <iostream>
#include <queue>
using namespace std;
int n,k;
int belt[200];  //벨트의 내구도
queue<int> robot;  //로봇의 위치
bool exist[200];    //벨트에 로봇존재여부
int cnt;
void rotate(){
    //벨트 회전
    int tmp=belt[2*n-1];
    for(int i=2*n-1;i>0;i--) belt[i]=belt[i-1];
    belt[0]=tmp;
    //로봇도 같이 회전
    int size=robot.size();
    for(int i=0;i<size;i++){
        int pos=robot.front();
        robot.pop();
        int nextPos=(pos<2*n-1?pos+1:0);
        exist[pos]=false;
        if(nextPos!=n-1) exist[nextPos]=true;
        if(nextPos!=n-1) robot.push(nextPos);
    }
}
void move(){
    int size=robot.size();
    for(int i=0;i<size;i++){
        int pos=robot.front();
        int nextPos=(pos<2*n-1?pos+1:0);
        robot.pop();
        if(exist[nextPos]||belt[nextPos]<1){
            robot.push(pos);
            continue;
        }
        exist[pos]=false;
        if(nextPos!=n-1) exist[nextPos]=true;
        belt[nextPos]--;
        if(belt[nextPos]==0) cnt++;
        if(nextPos!=n-1) robot.push(nextPos);
    }
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<2*n;i++) scanf("%d",&belt[i]);
    int ans=0;
    while(1){
        ans++;
        //1. 벨트 한 칸 회전
        rotate();
        //2. 로봇 이동
        move();
        //3. 로봇 올리기
        if(!exist[0]&&belt[0]>0){
            robot.push(0);
            belt[0]--;
            if(belt[0]==0) cnt++;
            exist[0]=true;
        }
        if(cnt>=k) break;
    }
    printf("%d",ans);
}