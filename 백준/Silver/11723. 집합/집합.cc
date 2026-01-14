#include <cstdio>
#include <cstring>

const int Z = 1 << 17;
char I[Z], *p = I, *e = I;
char O[Z], *w = O;

void F() {
    if (e - p < 20) {
        int n = e - p;
        memcpy(I, p, n);
        p = I;
        e = I + n + fread(I + n, 1, Z - n, stdin);
    }
}

int RI() {
    int x = 0;
    while (*p < 48 || *p > 57) p++;
    while (*p > 47 && *p < 58) x = (x << 3) + (x << 1) + *p++ - 48;
    return x;
}

int main() {
    F();
    int m = RI(), s = 0;
    while (m--) {
        F();
        while (*p < 33) p++;
        char c = *p;
        
        if (c == 'a') {
            if (*(p + 1) == 'l') s = 0xfffff, p += 3;
            else s |= 1 << RI() - 1;
        }
        else if (c == 'r') s &= ~(1 << RI() - 1);
        else if (c == 'c') {
            if (w - O > Z - 8) fwrite(O, 1, w - O, stdout), w = O;
            *w++ = 48 + (s >> RI() - 1 & 1);
            *w++ = 10;
        }
        else if (c == 't') s ^= 1 << RI() - 1;
        else s = 0, p += 5;
    }
    fwrite(O, 1, w - O, stdout);
}