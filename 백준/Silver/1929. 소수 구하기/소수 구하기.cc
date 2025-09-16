#include <stdio.h>

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
    int n, m;
    int *sta = &n, *end = &m;
    scanf("%d %d", sta, end);
    for (int i = *sta; i <= *end; i++)
    {
        if (soSu(i))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}