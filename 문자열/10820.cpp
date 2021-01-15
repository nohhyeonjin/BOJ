#include <bits/stdc++.h>
using namespace std;
int main(){
    char str[102];
    while(fgets(str,sizeof(str),stdin)!=NULL){
        int upper=0, lower=0, digit=0, space=0;
        for(int i=0;str[i]!='\0';i++){
            if(str[i]==' ') space++;
            else if(isdigit(str[i])) digit++;
            else if(isupper(str[i])) upper++;
            else if(islower(str[i])) lower++;
        }
        printf("%d %d %d %d\n",lower,upper,digit,space);
    }
}