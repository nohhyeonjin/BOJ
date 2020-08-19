#include <bits/stdc++.h>
#define MIN(x,y) (x<y?x:y)
using namespace std;
char s[1000000];
vector<char> v;
int main(){
    scanf("%s",s);
    char a=s[0];
    v.push_back(a);
    for(int i=1;i<strlen(s);i++){
        if(s[i]!=a){
            v.push_back(s[i]);
            a=s[i];
        }
    }
    int zeroCnt=0, oneCnt=0;
    for(int i=0;i<v.size();i++){
        if(v[i]=='0') zeroCnt++;
        else oneCnt++;
    }
    printf("%d",MIN(zeroCnt,oneCnt));
}