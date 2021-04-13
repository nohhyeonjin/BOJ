#include <iostream>
#include <algorithm>
using namespace std;
int n,m,r;
int a[300][300], b[300][300];
void rotate(){
    for(int i=0;i<min(n,m)/2;i++){
        //오->왼
        for(int j=i;j<m-1-i;j++) b[i][j]=a[i][j+1];
        //아래->위
        for(int j=i;j<n-1-i;j++) b[j][m-1-i]=a[j+1][m-1-i];
        //왼->오
        for(int j=1+i;j<m-i;j++) b[n-1-i][j]=a[n-1-i][j-1];
        //위->아래
        for(int j=1+i;j<n-i;j++) b[j][i]=a[j-1][i];
    }

    //배열 복사
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) a[i][j]=b[i][j];
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&r);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    }
    for(int i=0;i<r;i++) rotate();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ",a[i][j]);
        printf("\n");
    }
}