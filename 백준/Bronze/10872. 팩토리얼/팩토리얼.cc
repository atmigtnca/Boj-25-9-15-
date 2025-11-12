#include <stdio.h>

int main(){
    int a,b=1;
    scanf("%d",&a);

    for (int k = 2; k <= a; k++)
    {
        b *= k;
    }
    printf("%d\n",b);
    
    return 0;
}