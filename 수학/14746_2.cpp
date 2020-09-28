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
    int minDis=1e9;
    int minCnt=0;
    for(int i=1;i<n+m;i++){
        if(coordi[i-1].second!=coordi[i].second){
            int dis=abs(coordi[i-1].first-coordi[i].first);
            if(minDis==dis) minCnt++;
            if(dis<minDis){
                minDis=dis;
                minCnt=1;
            }             
        }
    }
    minDis+=abs(c1-c2);
    printf("%d %d",minDis,minCnt);
}