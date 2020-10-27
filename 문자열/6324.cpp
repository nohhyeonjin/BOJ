#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        string s;
        cin >> s;
        string protocol, host, port, path;
        int idx=0;
        for(;s[idx]!=':';idx++) protocol+=s[idx];
        idx+=3;
        bool portFlag=false;
        for(;s[idx]!='/';idx++){
            if(idx==s.size()) break;
            if(s[idx]==':'){
                portFlag=true;
                idx++;
            }
            if(!portFlag) host+=s[idx];
            if(portFlag) port+=s[idx];
        }
        idx+=1;
        for(;idx<s.size();idx++) path+=s[idx];
        
        if(port=="") port="<default>";
        if(path=="") path="<default>";

        cout << "URL #" << i << "\n";
        cout << "Protocol = " << protocol << "\n";
        cout << "Host     = " << host << "\n";
        cout << "Port     = " << port << "\n";
        cout << "Path     = " << path << "\n"; 
        cout << "\n";
    }
}