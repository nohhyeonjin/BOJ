#include <bits/stdc++.h>
using namespace std;
int n;
pair<double,double> star[101]; // 별번호->{x좌표,y좌표}
vector<pair<double,pair<int,int>>> edges;   // {거리,{별번호, 별번호}}
int parent[101];
double ans;
int findParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x]);
}
void unionParent(int a, int b){
    a=findParent(a);
    b=findParent(b);
    if(a>b) swap(a,b);
    parent[b]=a;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) parent[i]=i;
    for(int i=0;i<n;i++){
        double x,y;
        scanf("%lf %lf",&x,&y);
        star[i]={x,y};
    }
    for(int i=0;i<n;i++){
        double dist;
        for(int j=i+1;j<n;j++){
            double aX=star[i].first;
            double aY=star[i].second;
            double bX=star[j].first;
            double bY=star[j].second;
            dist=sqrt(pow(aX-bX,2)+pow(aY-bY,2));
            edges.push_back({dist,{i,j}});
        }
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++){
        int a=edges[i].second.first;
        int b=edges[i].second.second;
        double dist=edges[i].first;
        if(findParent(a)!=findParent(b)){
            unionParent(a,b);
            ans+=dist;
        }
    }
    printf("%.2f",ans);
}