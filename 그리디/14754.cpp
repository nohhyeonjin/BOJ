#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,sum;
long long arr[1000][1000];
int chk[1000][1000];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
            sum+=arr[i][j];
        }
    }
    //행체크
    for(int i=0;i<n;i++){
        int max=0;
        pair<int,int> maxIdx;
        for(int j=0;j<m;j++){
            if(arr[i][j]>max){
                max=arr[i][j];
                maxIdx={i,j};
            }
        }
        chk[maxIdx.first][maxIdx.second]=1;
    }
    //열체크
    for(int i=0;i<m;i++){
        int max=0;
        pair<int,int> maxIdx;
        for(int j=0;j<n;j++){
            if(arr[j][i]>max){
                max=arr[j][i];
                maxIdx={j,i};
            }
        }
        chk[maxIdx.first][maxIdx.second]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(chk[i][j]==1){
                ans+=arr[i][j];
            }
        }
    }
    printf("%lld",sum-ans);
}