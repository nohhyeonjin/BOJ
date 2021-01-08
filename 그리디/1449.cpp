#include <bits/stdc++.h>
using namespace std;
int n,l;
int pos[1001];
int main(){
    scanf("%d %d",&n,&l);
    for(int i=0;i<n;i++) scanf("%d",&pos[i]);
    sort(pos,pos+n);
    int right = pos[0]-0.5+l;
    int ans=1;
    for(int i=1;i<n;i++){
        if(pos[i]>right){
            right=pos[i]-0.5+l;
            ans++;
        }
    }
    printf("%d",ans);
}