#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int cut = 1, srt = 1;
    int cir = 10, rst = 0;

    while (srt <= n)
    {
        if (srt == cir)
        {
            cir *= 10;
            cut++;
        }
        rst += cut;
        srt++;
    }

    cout << rst << '\n';

    return 0;
}