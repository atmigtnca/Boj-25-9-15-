#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n], b[n], ct[n];
    int *pt = ct, *wp = a, *lp = b;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", a + i, b + i);
    }

    for (int i = 0; i < n; i++)
    {
        int k = 1;
        int *ut = &k;
        for (int j = 0; j < n; j++)
        {
            if (i != j && *(wp + i) < *(wp + j) && *(lp + i) < *(lp + j))
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