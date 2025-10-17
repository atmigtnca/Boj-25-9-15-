#include<stdio.h>

int hyo(int a, int b);

int main(void){
    int a,b;
    scanf("%d %d", &a, &b);
    if (a <= 1000 && b <= 1000)
    {
        printf("%d\n", hyo(a,b));
    }
    return 0;
}

int hyo(int a, int b){
    int rst;
    rst = (a+b)*(a-b);

    return rst;
}