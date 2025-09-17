#include <stdio.h>
#include <string.h>

int main(void)
{
    char ar[101] = {'\0'};
    int ka[101] = {0};
    int *pkr = ka;
    scanf("%s", ar);
    int len = strlen(ar);
    for (int i = 0; i < len; i++)
    {
        *(pkr + i) = ar[i];
    }
    int cut = len; // 총 길이에서 차감
    int ct = 0;    // 증가증가

    while (ct < len)
    {
        if (*(pkr + ct) == 99 && (len - ct >= 2))
        {
            if (*(pkr + (ct + 1)) == 61 || *(pkr + (ct + 1)) == 45)
            {
                cut--;
                ct++;
                continue;
            }
        }
        else if (*(pkr + ct) == 100 && (len - ct >= 2))
        {
            if (*(pkr + (ct + 1)) == 45)
            {
                cut--;
                ct += 2;
                continue;
            }
            else if (*(pkr + (ct + 1)) == 122 && *(pkr + (ct + 2)) == 61)
            {
                cut -= 2;
                ct += 3;
                continue;
            }
        }
        else if ((*(pkr + ct) == 106) && (ct > 0))
        {
            if (*(pkr + (ct - 1)) == 108 || *(pkr + (ct - 1)) == 110)
            {
                cut--;
                ct++;
                continue;
            }
        }
        else if ((*(pkr + ct) == 61) && (ct > 0))
        {
            if (*(pkr + (ct - 1)) == 115 || *(pkr + (ct - 1)) == 122)
            {
                cut--;
                ct++;
                continue;
            }
        }
        ct++;
    }

    printf("%d\n", cut);
    return 0;
}