#include <stdio.h>

long long f(long long mid, int n, int *let)
{
    long long cut = 0;
    for (int i = 0; i < n; i++)
    {
        cut += *(let + i) / mid;
    }
    return cut;
}

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    int let[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &let[i]);
    }

    int left = 1;
    long long right = 2147483647;

    while (left < right)
    {
        long long mid = (left + right + 1) / 2;
        if (f(mid, n, let) >= k)
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("%d\n", left);

    return 0;
}