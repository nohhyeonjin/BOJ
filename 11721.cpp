#include <iostream>
int main(){
    char words[101];
    scanf("%s",words);
    int i=0;
    while(words[i]!='\0'){
        printf("%c",words[i]);
        i++;
        if(i%10==0){
            printf("\n");
        }
    }
}