#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n,k;
int dist[401][401];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        dist[a][b]=1;
    }
    for(int k=1;k<=n;k++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                if(dist[a][k]==1&&dist[k][b]==1) dist[a][b]=1;
            }
        }
    }
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(dist[a][b]==0&&dist[b][a]==0) printf("0\n"); //a->b, b->a 모두 길이 없음
        if(dist[a][b]==1&&dist[b][a]==0) printf("-1\n");    //a->b는 길이있고, b->a는 길이 없음 즉, a가 b보다 먼저일어남
        if(dist[a][b]==0&&dist[b][a]==1) printf("1\n"); //a->b는 길이없고, b->a는 길이 있음 즉, b가 a보다 먼저일어남
    }
}