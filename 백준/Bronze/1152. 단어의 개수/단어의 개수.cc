#include <stdio.h>
#include <string.h>
#define LE 1000010

int main(void)
{
    int cut = 1;
    char dan[LE] = {'\0'};
    fgets(dan, sizeof(dan), stdin);
    const int le = strlen(dan);
    if (dan[0] == ' ')
    {
        cut--;
    }
    if (dan[le - 2] == ' ')
    {
        cut--;
    }

    for (int f = 0; f < le; f++)
    {
        if (dan[f] == ' ')
        {
            cut++;
        }
    }

    printf("%d\n", cut);

    return 0;
}