#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string lku = "LoveisKoreaUniversity ";
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cout << lku;
    }

    cout << '\n';

    return 0;
}