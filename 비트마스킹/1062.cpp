#include <iostream>
#include <vector>
using namespace std;
int n,k;
int ans;
vector<int> words;
int count(int mask){
    int cnt=0;
    for(int word:words){
        if((word&((1<<26)-1-mask))==0) cnt++;
    }
    return cnt;
}
void go(int idx, int cnt, int mask){
    if(cnt==k){
        //count
        int cnt=count(mask);
        if(cnt>ans) ans=cnt;
        return;
    }
    if(idx==26) return;
    //배우기
    go(idx+1,cnt+1,mask|(1<<idx));
    //배우지않기
    if(!(idx+'a'=='a'||idx+'a'=='n'||idx+'a'=='t'||idx+'a'=='i'||idx+'a'=='c')){
        go(idx+1,cnt,mask);
    }
}
int main(){
    cin >> n >> k;
    //단어들 비트마스크로 저장
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int word=0;
        for(char c:s) word|=(1<<(c-'a'));
        words.push_back(word);
    }
    //글자 가르치기
    go(0,0,0);
    cout << ans;
}