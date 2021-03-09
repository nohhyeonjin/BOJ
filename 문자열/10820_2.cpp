#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    for(int i=0;i<100;i++){
        int a=0,b=0,c=0,d=0;
        getline(cin,s);
        for(int j=0;j<s.size();j++){
            if(s[j]>='a'&&s[j]<='z') a++;
            if(s[j]>='A'&&s[j]<='Z') b++;
            if(isdigit(s[j])) c++;
            if(s[j]==' ') d++;
        }
        cout << a << " " << b << " " << c << " " << d << "\n";
    }
}