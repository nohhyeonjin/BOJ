#include <bits/stdc++.h>
using namespace std;
int l,c;
char charArr[15];
bool selected[15];
void dfs(int idx, int cnt){
    if(cnt==l){
        int vowel=0, consonant=0;
        for(int i=0;i<c;i++){
            if(selected[i]){
                char c=charArr[i];
                if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') vowel++;
                else consonant++;
            }
        }
        if(vowel>=1&&consonant>=2){
            for(int i=0;i<c;i++){
                if(selected[i]) cout << charArr[i];
            }
            cout << "\n";
        }
        return;
    }
    for(int i=idx;i<c;i++){
        if(selected[i]) continue;
        selected[i]=true;
        dfs(i,cnt+1);
        selected[i]=false;
    }
}
int main(){
    scanf("%d %d",&l,&c);
    for(int i=0;i<c;i++) cin >> charArr[i];
    sort(charArr,charArr+c);
    dfs(0,0);
}