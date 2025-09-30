#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int ga[n + 1];
    ga[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        if (i == 1)
        {
            ga[i] = a;
            continue;
        }
        ga[i] = ga[i - 1] + a;
    }

    for (int i = 0; i < m; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", ga[e] - ga[s - 1]);
    }

    return 0;
}