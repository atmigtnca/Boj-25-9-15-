#include <stdio.h>
#include <string.h>
#define LE 60

int main(void)
{
    float gp = 0, aL = 0; // gp: 학점

    for (int j = 0; j < 20; j++)
    {
        char obj[LE] = {'\0'};
        fgets(obj, sizeof(obj), stdin);
        int ln = strlen(obj);
        float gP = 0, rA = 0;
        if (obj[ln - 2] == 'P')
        {
            // printf("\n1-gp= %f aL=%f\n", gp, aL);
            continue;
        }
        else if (obj[ln - 2] == 'F')
        {
            aL += obj[ln - 6] - 48;
            // printf("\n2-gp= %f aL=%f\n", gp, aL);
            continue;
        }
        else
        {
            rA += 69 - obj[ln - 3];
            rA += (obj[ln - 2] == 48) ? 0 : 0.5;
            gP += obj[ln - 7] - 48;
            gp += gP * rA;
            aL += gP;
            // printf("\n3-gp= %f aL=%f\n", gp, aL);
        }
    }

    // if (gp == 0)
    // {
    //     printf("0.000000\n");
    //     return 0;
    // }

    // printf("\nf-gp= %f aL=%f\n", gp, aL);

    printf("%f\n", (gp / aL) + 0.00000001);

    return 0;
}