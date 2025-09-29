#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int sal[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sal[i]);
    }
    qsort(sal, n, sizeof(int), compare);

    int x;
    scanf("%d", &x);

    int MAX = n;

    for (int i = n - 1; i >= 0; i--)
    {
        MAX = i;
        if (sal[i] < x)
        {
            break;
        }
    }

    if (MAX == 0)
    {
        MAX = n;
    }

    int cut = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i; j < MAX + 1; j++)
        {
            if (i == j)
            {
                continue;
            }
            int rst = sal[i] + sal[j];
            if (rst == x)
            {
                cut++;
            }
            else if (rst > x)
            {
                break;
            }
        }
    }

    printf("%d\n", cut);

    return 0;
}