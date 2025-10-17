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

    for (size_t i = 0; i < 13; i++)
    {
        if (i == idx)
        {
            continue;
        }
        int rt = isbn[i] - '0', ut = i % 2 ? 3 : 1;
        all += rt * ut;
    }

    int rst = 0;

    for (size_t i = 0; i < 10; i++)
    {
        int ut = idx % 2 ? 3 : 1;
        if ((all + (i * ut)) % 10 == 0)
        {
            rst = i;
            break;
        }
    }

    cout << rst << '\n';

    return 0;
}