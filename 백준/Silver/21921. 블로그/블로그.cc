#include <stdio.h>

int main(void)
{
    int n, k, sum = 0, MAX = 0, day = 1;
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
            day = 1;
        }
        else if (MAX == sum)
        {
            day++;
        }
    }
    if (MAX == 0)
    {
        printf("SAD\n");
    }
    else
    {
        printf("%d\n%d\n", MAX, day);
    }

    return 0;
}
