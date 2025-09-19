#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int car[2 * (n - 1)];
    if (n == 1)
    {
        printf("1\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        car[i] = i + 1;
    }

    int j = 1;
    int la = n;

    while (j < 2 * (n - 1))
    {
        int n = car[j];
        car[la] = n;
        j += 2;
        la++;
    }

    printf("%d\n", car[j - 2]);

    return 0;
}