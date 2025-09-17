#include <stdio.h>
#include <string.h>

int main(void)
{
    char ar[101] = {'\0'};
    scanf("%s", ar);
    int len = strlen(ar);
    int cut = len; // 총 길이에서 차감
    int ct = 0;    // 증가증가

    while (ct < len)
    {
        if (ar[ct] == 'c' && (len - ct >= 2))
        {
            if (ar[ct + 1] == '=' || ar[ct + 1] == '-')
            {
                cut--;
                ct++;
                continue;
            }
        }
        else if (ar[ct] == 'd' && (len - ct >= 2))
        {
            if (ar[ct + 1] == '-')
            {
                cut--;
                ct += 2;
                continue;
            }
            else if (ar[ct + 1] == 'z' && ar[ct + 2] == '=')
            {
                cut -= 2;
                ct += 3;
                continue;
            }
        }
        else if (ar[ct] == 'j' && (ct > 0))
        {
            if (ar[ct - 1] == 'l' || ar[ct - 1] == 'n')
            {
                cut--;
                ct++;
                continue;
            }
        }
        else if (ar[ct] == '=' && (ct > 0))
        {
            if (ar[ct - 1] == 's' || ar[ct - 1] == 'z')
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