#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,l;
int a[100][100];
int ans;
bool go(vector<int> v){
    bool visited[100];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<n-1;i++){
        int cur=v[i], next=v[i+1];
        if(cur==next) continue;
        if(abs(next-cur)>=2) return false;
        if(cur<next){
            for(int j=i+1-l;j<i+1;j++){
                if(j<0||visited[j]||v[j]!=next-1) return false;
                visited[j]=true;
            }
        }
        if(cur>next){
            for(int j=i+1;j<=i+l;j++){
                if(j>=n||visited[j]||v[j]!=cur-1) return false;
                visited[j]=true;
            }
        }
    }
    return true;
}
int main(){
    scanf("%d %d",&n,&l);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    }
    //한줄씩 복사
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<n;j++) v.push_back(a[i][j]);
        if(go(v)) ans++;
    }
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<n;j++) v.push_back(a[j][i]);
        if(go(v)) ans++;
    }
    printf("%d",ans);
}