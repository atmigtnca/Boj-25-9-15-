#include <stdio.h>
#include <string.h>

int main(void)
{
    char ar[100];
    int ch[26] = {0};
    scanf("%s", ar);

    for (int i = 0; i < strlen(ar); i++)
    {
        int n = ar[i] - 97;
        ch[n]++;
    }

    for (int j = 0; j < 26; j++)
    {
        printf("%d ", ch[j]);
    }

    return 0;
}