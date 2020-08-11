#include <stdio.h>
int a[1000000];
int b[1000000];
int result[2000000];
void merge(int n, int m){
    int i=0,j=0,k=0;
    while(i<n&&j<m){
        if(a[i]<b[j]){
            result[k]=a[i];
            i++;
        }else{
            result[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n){ 
        result[k]=a[i];
        i++; k++;
    }
    while(j<m){
        result[k]=b[j];
        j++; k++;
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    merge(n,m);
    for(int i=0;i<n+m;i++) printf("%d ",result[i]);
}