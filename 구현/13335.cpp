#include <bits/stdc++.h>
using namespace std;
int n,w,l,ans;  //w-다리길이 l-최대하중
int truck[1000];
int main(){
    scanf("%d %d %d",&n,&w,&l);
    for(int i=0;i<n;i++) scanf("%d",&truck[i]);
    queue<int> q;
    for(int i=0;i<w;i++) q.push(0);
    int qW=0, 
    int truckCnt=0, outCnt=0;
    int truckIdx=0;
    while(1){
        if(outCnt==n) break;    //트럭 다 나갔으면 stop
        if(q.front()>0){
            truckCnt--;
            outCnt++;
        }
        qW-=q.front();
        q.pop();
        int tW=truck[truckIdx];
        if(qW+tW<=l&&truckCnt<w){
            q.push(tW);
            qW+=tW;
            truckIdx++;
            truckCnt++;
        }else{
            q.push(0);
        }
        ans++;
    }
    printf("%d",ans);
}