#include <bits/stdc++.h>
using namespace std;
int n,m,c1,c2;
vector<pair<int,int>> coordi;   //coordinate,type) type 0-p 1-q
int main(){
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    for(int i=0;i<n;i++){
        int num; scanf("%d",&num);
        coordi.push_back({num,0});
    }
    for(int i=0;i<m;i++){
        int num; scanf("%d",&num);
        coordi.push_back({num,1});
    }
    sort(coordi.begin(),coordi.end());
    //get distance between a closest pair of P and Q
    int minDis=1e9;
    for(int i=0;i<n+m;i++){
        int type=coordi[i].second;
        int cur=coordi[i].first;
        if(type==0){
            if(i!=0){
                int prev=coordi[i-1].first;
                int prevType=coordi[i-1].second;
                if(prevType!=0) minDis=min(minDis,abs(cur-prev));
            }
            int next=coordi[i+1].first;
            int nextType=coordi[i+1].second;
            if(nextType!=0) minDis=min(minDis,abs(cur-next));
        }
    }
    //get the number of closest pairs of P and Q
    int minCnt=0;
    for(int i=0;i<n+m;i++){
        int type=coordi[i].second;
        int cur=coordi[i].first;
        if(type==0){
            if(i!=0){
                int prev=coordi[i-1].first;
                int prevType=coordi[i-1].second;
                if(prevType!=0&&abs(cur-prev)==minDis) minCnt++;
            }
            int next=coordi[i+1].first;
            int nextType=coordi[i+1].second;
            if(nextType!=0&&abs(cur-next)==minDis) minCnt++;    
        }
    }
    //print answer
    minDis+=abs(c1-c2);
    printf("%d %d",minDis,minCnt);
}