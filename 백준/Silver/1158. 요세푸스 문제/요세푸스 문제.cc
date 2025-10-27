#include <stdio.h>
int a[5000], o[5000];
int main(){int n,k,i,j,p=0,m;scanf("%d%d",&n,&k);for(i=0;i<n;i++)a[i]=i+1;for(m=n,i=0;i<n;i++){p=(p+k-1)%m;o[i]=a[p];for(j=p;j<m-1;j++)a[j]=a[j+1];m--;}putchar('<');for(i=0;i<n;i++){printf("%d",o[i]);if(i<n-1)printf(", ");}puts(">");}