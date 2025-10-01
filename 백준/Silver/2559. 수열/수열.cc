#include <stdio.h>

int main(void)
{
    int n, k, sum = 0, MAX = 0;
    scanf("%d %d", &n, &k);

    int rcd[n];

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &rcd[i]);
        sum += rcd[i];
    }

    MAX = sum;

    for (int i = k, t = 0; i < n; i++, t++)
    {
        scanf("%d", &rcd[i]);
        sum = sum + rcd[i] - rcd[t];
        if (sum > MAX)
        {
            MAX = sum;
        }
    }

    printf("%d\n", MAX);

    return 0;
}