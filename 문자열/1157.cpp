#include <bits/stdc++.h>
using namespace std;
int alpha[26];
int maxValue, maxIdx;
int main(){
    string s;
    cin >> s;
    transform(s.begin(),s.end(),s.begin(),::toupper);
    for(int i=0;i<s.size();i++){
        alpha[s[i]-'A']++;
        if(alpha[s[i]-'A']>maxValue){
            maxIdx=s[i]-'A';
            maxValue=alpha[maxIdx];
        }
    }
    int maxCnt=0;
    for(int i=0;i<26;i++){
        if(alpha[i]==maxValue) maxCnt++;
    }
    if(maxCnt>1) printf("?");
    else printf("%c",maxIdx+'A'); 
}