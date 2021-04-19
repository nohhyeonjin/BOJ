#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int ans;
int alpha[26];
vector<string> words;
vector<char> letters;
int digit[10];
int chk(){
    for(int i=0;i<letters.size();i++){
        alpha[letters[i]-'A']=digit[i];
    }
    int sum=0;
    for(int i=0;i<words.size();i++){
        string s=words[i];
        int val=0;
        for(int j=0;j<s.size();j++){
            val=val*10+alpha[s[j]-'A'];
        }
        sum+=val;
    }
    return sum;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        words.push_back(s);
        for(int j=0;j<s.size();j++) letters.push_back(s[j]);
    }
    sort(letters.begin(),letters.end());
    letters.erase(unique(letters.begin(),letters.end()),letters.end());
    for(int i=0;i<10;i++) digit[i]=9-i;
    do{
        int sum=chk();
        if(sum>ans) ans=sum;
    }while(prev_permutation(digit, digit+letters.size()));
    cout << ans;
}