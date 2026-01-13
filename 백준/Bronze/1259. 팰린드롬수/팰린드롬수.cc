#include <stdio.h>
#include <string.h>

int ptr(int a) {
    int max = 0, rst = 0;
    char ptr[6] = {'\0'};
    sprintf(ptr, "%d", a);
    max = strlen(ptr);
    int ct = max / 2;
    for (int a = 0, b = max - 1; a < b; a++, b--) {
        rst += (ptr[a] == ptr[b]) ? 1 : 0;
    }
    return (rst == ct ? 1 : 0);
}

int main(void) {
    int n, r = 1;
    while (r) {
        scanf("%d", &n);
        if (n >= 10) {
            printf("%s\n", (ptr(n) == 1 ? "yes" : "no"));
        } else if (n < 10 && n > 0) {
            printf("yes\n");
        } else {
            r = 0;
        }
    }
    return 0;
}