#include <iostream>
#include <string>
using namespace std;
int n,m;
int paper[4][4];
int ans;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) scanf("%1d",&paper[i][j]);
    }
    for(int bit=0;bit<(1<<n*m);bit++){  //0-가로, 1-세로
        //가로
        int sum=0;
        for(int i=0;i<n;i++){
            int num=0;
            for(int j=0;j<m;j++){
                if((bit&(1<<i*m+j))==0){
                    num=num*10+paper[i][j];
                }else{
                    sum+=num;
                    num=0;
                }
            }
            sum+=num;
        }
        //세로
        for(int i=0;i<m;i++){
            int num=0;
            for(int j=0;j<n;j++){
                if((bit&(1<<j*m+i))!=0){
                    num=num*10+paper[j][i];
                }else{
                    sum+=num;
                    num=0;
                }
            }
            sum+=num;
        }
        if(sum>ans) ans=sum;
    }
    printf("%d",ans);
}