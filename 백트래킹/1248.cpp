#include <iostream>
using namespace std;
int n;
int op[10][10];
int ans[10];
bool ok(int idx){
    int sum=0;
    for(int i=idx;i>=0;i--){
        sum+=ans[i];
        if(op[i][idx]==0&&sum!=0) return false;
        else if(op[i][idx]<0&&sum>=0) return false;
        else if(op[i][idx]>0&&sum<=0) return false;
    }
    return true;
}
void go(int idx){
    if(idx==n){
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        exit(0);
    }
    if(op[idx][idx]==0){
        ans[idx]=0;
        if(ok(idx)) go(idx+1);
    }else{
        for(int i=1;i<=10;i++){
            ans[idx]=op[idx][idx]*i;
            if(ok(idx)){
                go(idx+1);
            }
        }
    }
}
int main(){
    cin >> n;
    string s;
    cin >> s;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(s[cnt]=='0') op[i][j]=0;
            if(s[cnt]=='-') op[i][j]=-1;
            if(s[cnt]=='+') op[i][j]=1;
            cnt++;
        }
    }
    go(0);
}