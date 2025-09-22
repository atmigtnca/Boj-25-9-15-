#include <stdio.h>
#include <string.h>
#define LE 60

int main(void)
{
    float gp = 0, aL = 0;

    for (int j = 0; j < 20; j++)
    {
        char obj[LE] = {'\0'};
        fgets(obj, sizeof(obj), stdin);
        int ln = strlen(obj);
        float gP = 0, rA = 0;
        if (obj[ln - 2] == 'P')
        {
            continue;
        }
        else if (obj[ln - 2] == 'F')
        {
            aL += obj[ln - 6] - 48;
            continue;
        }
        else
        {
            rA += 69 - obj[ln - 3];
            rA += (obj[ln - 2] == 48) ? 0 : 0.5;
            gP += obj[ln - 7] - 48;
            gp += gP * rA;
            aL += gP;
        }
    }

    printf("%.5f\n", gp / aL);

    return 0;
}