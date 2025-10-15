#include <iostream>
using namespace std;

void cng(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;

    int mina = a, minb = b;

    int rml;
    while (minb)
    {
        rml = mina % minb;
        cng(mina, minb);
        minb = rml;
    }

    int maxNum = (a * b) / mina;

    cout << mina << '\n'
         << maxNum << '\n';

    return 0;
}