#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b){int x=*(const int*)a,y=*(const int*)b;return x<y?-1:x>y;}

int main(){
    int n,m,x; scanf("%d",&n);
    int a[n]; for(int i=0;i<n;i++) scanf("%d",a+i);
    qsort(a,n,sizeof*a,cmp);
    scanf("%d",&m);
    while(m--){
        scanf("%d",&x);
        puts(bsearch(&x,a,n,sizeof*a,cmp) ? "1" : "0");
    }
}