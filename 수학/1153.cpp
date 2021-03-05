#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;
int n;
bool arr[MAX];
vector<int> prime;
int main(){
    scanf("%d",&n);
    for(int i=2;i*i<=n;i++){
        if(arr[i]) continue;
        for(int j=i*2;j<=n;j+=i) arr[j]=true;
    }
    for(int i=2;i<=n;i++) if(!arr[i]) prime.push_back(i);
    int a,b;
    if(n<8) printf("-1");
    else{
        for(int i=0;i<prime.size();i++){
            bool find=false;
            for(int j=0;j<prime.size();j++){
                a=prime[i]; b=prime[j];
                int sum=a+b;
                if(((n%2==0)&&(sum+4==n))||((n%2==1)&&(sum+5==n))){
                    find=true;
                    break;
                }
            }
            if(find){
                printf("%d %d ",a,b);
                break;
            }
        }
        if(n%2==0) printf("2 2");
        else printf("2 3");
    }
}