#include <iostream>
int main(){
    int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    int month,day;
    scanf("%d %d",&month,&day);
    for(int i=0;i<month;i++){
        sum+=days[i];
    }
    sum+=day;
    switch(sum%7){
        case 0:
            printf("SUN");
            break;
        case 1:
            printf("MON");
            break;
        case 2:
            printf("TUE");
            break;    
        case 3:
            printf("WED");
            break;
        case 4:
            printf("THU");
            break;
        case 5:
            printf("FRI");
            break;
        case 6:
            printf("SAT");
            break;
    }
}