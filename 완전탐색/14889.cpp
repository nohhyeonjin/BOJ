#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int n;
int ans=INT_MAX;
int s[20][20];
vector<int> a,b;
void go(int idx){
    if(a.size()>n/2) return;
    if(b.size()>n/2) return;
    if(idx==n){
        int t1=0, t2=0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                if(i==j) continue;
                t1+=s[a[i]][a[j]];
                t2+=s[b[i]][b[j]];
            }
        }
        int gap=abs(t1-t2);
        if(gap<ans) ans=gap;
        return;
    }
    //a에 넣음
    a.push_back(idx);
    go(idx+1);
    a.pop_back();
    //b에 넣음
    b.push_back(idx);
    go(idx+1);
    b.pop_back();
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> s[i][j];
        }
    }
    go(0);
    cout << ans;
}