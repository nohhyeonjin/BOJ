#include <iostream>
using namespace std;
int n,m,r;
int a[100][100],b[100][100];
void go(int order){
    if(order==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) b[i][j]=a[n-i-1][j];
        }
    }
    if(order==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) b[i][j]=a[i][m-j-1];
        }
    }
    if(order==3){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) b[i][j]=a[n-j-1][i];
        }
        swap(n,m);
    }
    if(order==4){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) b[i][j]=a[j][m-i-1];
        }
        swap(n,m);
    }
    if(order==5){
        for(int i=0;i<n/2;i++){
            for(int j=0;j<m/2;j++) b[i][j]=a[i+n/2][j];
        }
        for(int i=0;i<n/2;i++){
            for(int j=m/2;j<m;j++) b[i][j]=a[i][j-m/2];
        }
        for(int i=n/2;i<n;i++){
            for(int j=m/2;j<m;j++) b[i][j]=a[i-n/2][j];
        }
        for(int i=n/2;i<n;i++){
            for(int j=0;j<m/2;j++) b[i][j]=a[i][m/2+j];
        }
    }
    if(order==6){
        for(int i=0;i<n/2;i++){
            for(int j=0;j<m/2;j++) b[i][j]=a[i][m/2+j];
        }
        for(int i=0;i<n/2;i++){
            for(int j=m/2;j<m;j++) b[i][j]=a[i+n/2][j];
        }
        for(int i=n/2;i<n;i++){
            for(int j=0;j<m/2;j++) b[i][j]=a[i-n/2][j];
        }
        for(int i=n/2;i<n;i++){
            for(int j=m/2;j<m;j++) b[i][j]=a[i][j-m/2];
        }
    }
    //배열복사
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) a[i][j]=b[i][j];
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&r);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    }
    for(int i=0;i<r;i++){
        int order;
        scanf("%d",&order);
        go(order);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ",a[i][j]);
        printf("\n");
    }
}