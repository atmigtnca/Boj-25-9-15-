#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int da[n][2], ct[n];
    int *pt = ct;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &da[i][0], &da[i][1]);
    }

    for (int i = 0; i < n; i++)
    {
        int a = 1;
        int *ut = &a;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if ((da[i][0] < da[j][0]) && (da[i][1] < da[j][1]))
            {
                (*ut)++;
            }
        }
        *(pt + i) = *ut;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(pt + i));
    }

    return 0;
}