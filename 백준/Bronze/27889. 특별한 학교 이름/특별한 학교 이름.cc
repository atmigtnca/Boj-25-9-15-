#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> sch;
    sch.reserve(4);

    sch.push_back("North London Collegiate School");
    sch.push_back("Branksome Hall Asia");
    sch.push_back("Korea International School");
    sch.push_back("St. Johnsbury Academy");

    string sname;
    cin >> sname;

    int idx;
    if (sname[0] == 'N')
    {
        idx = 0;
    }
    else if (sname[0] == 'B')
    {
        idx = 1;
    }
    else if (sname[0] == 'K')
    {
        idx = 2;
    }
    else
    {
        idx = 3;
    }

    cout << sch[idx] << '\n';

    return 0;
}