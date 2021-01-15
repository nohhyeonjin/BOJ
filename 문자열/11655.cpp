#include <bits/stdc++.h>
using namespace std;
int main(){
    char str[101];
    fgets(str,101,stdin);
    for(int i=0;str[i]!='\0';i++){
        char c=str[i];
        if(isupper(c)){
            if(c+13>'Z') c=c+13-26;
            else c=c+13;
        }
        if(islower(c)){
            if(c+13>'z') c=c+13-26;
            else c=c+13;
        }
        printf("%c",c);
    }
}