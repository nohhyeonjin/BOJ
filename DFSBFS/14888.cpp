#include <bits/stdc++.h>
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)
int num[100];
int oper[4];
int min=987654321;
int max=-987654321;
int n;
void dfs(int plus, int minus, int mul, int div, int idx, int sum){
    if(idx==n){
        min=MIN(min,sum);
        max=MAX(max,sum);
    }
    if(plus>0) dfs(plus-1,minus,mul,div,idx+1,sum+num[idx]);
    if(minus>0) dfs(plus,minus-1,mul,div,idx+1,sum-num[idx]);
    if(mul>0) dfs(plus,minus,mul-1,div,idx+1,sum*num[idx]);
    if(div>0) dfs(plus,minus,mul,div-1,idx+1,sum/num[idx]);
}
void input(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    for(int i=0;i<4;i++) scanf("%d",&oper[i]);
}
int main(){
    input();
    dfs(oper[0],oper[1],oper[2],oper[3],1,num[0]);
    printf("%d\n%d",max,min);
}