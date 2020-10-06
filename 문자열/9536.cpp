#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    cin >> t;
    cin.ignore();
    while(t--){
        vector<string> sounds,splitS;
        string s;
        getline(cin,s);
        //split s
        istringstream iss(s);
        copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(splitS));
        //입력
        while(1){
            string sound;
            getline(cin,sound);
            if(sound=="what does the fox say?") break;
            int idx=sound.find("goes");
            sound=sound.substr(idx+5);
            sounds.push_back(sound);
        }
        //제거
        for(int i=0;i<sounds.size();i++){
            int len=splitS.size();
            for(int j=0;j<len;j++){
                if(splitS[j]==sounds[i]) splitS[j]="";
            }
        }
        //출력
        for(int i=0;i<splitS.size();i++) if(splitS[i]!="") cout << splitS[i] << " ";
        cout << "\n";
    }
}