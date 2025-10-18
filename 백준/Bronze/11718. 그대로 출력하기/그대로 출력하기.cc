#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string hel;
    hel.reserve(100);

    while (getline(cin, hel))
    {
        cout << hel << '\n';
    }

    return 0;
}