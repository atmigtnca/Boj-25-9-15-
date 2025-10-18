#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ot;

    while (getline(cin, ot))
    {
        cout << ot << '\n';
    }

    return 0;
}