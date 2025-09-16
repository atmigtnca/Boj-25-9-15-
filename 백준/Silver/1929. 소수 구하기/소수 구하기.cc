#include <stdio.h>
#define L 1000000

int soSu(int start)
{
    if (start < 2)
        return 0;
    for (int i = 2; i * i <= start; i++)
        if (start % i == 0)
            return 0;
    return 1;
}

int main(void)
{
    int n, m, ct = 0, ar[L];
    int *sta = &n, *end = &m, *sosu = ar;
    scanf("%d %d", sta, end);
    for (int i = *sta; i <= *end; i++)
    {
        if (soSu(i))
        {
            *(sosu + ct) = i;
            ct++;
        }
    }
    for (int i = 0; i < ct; i++)
    {
        printf("%d\n", ar[i]);
    }

    return 0;
}