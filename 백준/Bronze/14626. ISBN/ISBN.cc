#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string isbn;
    isbn.reserve(13);

    cin >> isbn;

    auto star = find(isbn.begin(), isbn.end(), '*');
    int idx = distance(isbn.begin(), star), all = 0;

    for (size_t i = 0; i < 12; i++)
    {
        if (i == idx)
        {
            continue;
        }
        int rt = isbn[i] - '0';
        if (i % 2 != 0)
        {
            all += rt * 3;
            continue;
        }
        all += rt;
    }
    all += isbn[12] - '0';

    int rst = 0;
    ++idx;

    for (size_t i = 1; i < 10; i++)
    {
        int I;
        if (idx % 2 == 0)
        {
            I = i * 3;
        }
        else
        {
            I = i;
        }
        int tet = all + I;
        if (tet % 10 == 0)
        {
            rst = i;
            break;
        }
    }

    cout << rst << '\n';

    return 0;
}