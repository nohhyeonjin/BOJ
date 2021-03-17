#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;
int k;
char c[9];
bool selected[10];
int result[10];
long long minValue=LLONG_MAX,maxValue;
string minAns,maxAns;
void dfs(int cnt){
    if(cnt==k+1){
        bool flag=true;
        for(int i=0;i<k;i++){
            int l=result[i];
            int r=result[i+1];
            char a=c[i];
            if(a=='<'){
                if(l>r){
                    flag=false;
                    break;
                } 
            }
            if(a=='>'){
                if(l<r){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            string s="";
            for(int i=0;i<k+1;i++) s+=to_string(result[i]);
            if(stoll(s)<minValue){
                minValue=stoll(s);
                minAns=s;
            }
            if(stoll(s)>maxValue){
                maxValue=stoll(s);
                maxAns=s;
            }
        }
        return;
    }
    for(int i=0;i<10;i++){
        if(selected[i]) continue;
        selected[i]=true;
        result[cnt]=i;
        dfs(cnt+1);
        selected[i]=false;
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> k;
    for(int i=0;i<k;i++) cin >> c[i];
    dfs(0);
    cout << maxAns << "\n" << minAns;
}