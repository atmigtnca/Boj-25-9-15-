#include<stdio.h>

int is_so(int n){
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++)if (n % i == 0) return 0;
    return 1;
}

int main(void){
    int ge, su=0;
    scanf("%d", &ge);
    int soso[ge];


    for (int i = 0; i < ge; i++){
        scanf("%d", &soso[i]);
        if (is_so(soso[i]))su++;
    }

    printf("%d\n", su);

    return 0;
}