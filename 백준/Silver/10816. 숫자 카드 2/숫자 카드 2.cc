#include <stdio.h>
#define LE 20000001
#define P 10000000

int main(void)
{
    int n, m, sar[LE] = {0};
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int tm;
        scanf("%d", &tm);
        sar[tm + P]++;
    }

    scanf("%d", &m);
    // int fnl[rst];

    for (int k = 0; k < m; k++)
    {
        int rt;
        scanf("%d", &rt);
        printf("%d ", sar[rt + P]);
    }

    // for (int j = 0; j < rst; j++)
    // {
    //     printf("%d ", fnl[j]);
    // }

    return 0;
}