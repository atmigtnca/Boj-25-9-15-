#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        int rst = 0;
        char ho[51] = {'\0'};
        scanf("%s", ho);
        const int ln = strlen(ho);
        if (ln % 2 != 0)
        {
            rst = 0;
        }
        else
        {
            int ct = 0;
            for (int k = 0; k < ln; k++)
            {
                if (ct < 0)
                {
                    rst = 0;
                    goto ho;
                }
                if (ho[k] == '(')
                {
                    ct++;
                }
                else
                {
                    ct--;
                }
            }
            if (ct == 0)
            {
                rst = 1;
            }
            else
            {
                rst = 0;
            }
        }
    ho:
        printf("%s\n", rst == 0 ? "NO" : "YES");
    }

    return 0;
}