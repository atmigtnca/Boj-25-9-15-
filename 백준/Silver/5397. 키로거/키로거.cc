#include <iostream>
#include <list>
#include <string>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        string l;  // 입력받을 string l
        cin >> l;

        list<char> passwd;
        auto curs = passwd.end();  // 커서

        for (auto& wd : l)
        {
            if (wd == '<')
            {
                if (curs != passwd.begin())
                {
                    curs--;
                }
            }
            else if (wd == '>')
            {
                if (curs != passwd.end())
                {
                    curs++;
                }
            }
            else if (wd == '-')
            {
                if (passwd.size() != 0 && curs != passwd.begin())
                {
                    curs--;
                    curs = passwd.erase(curs);
                }
            }
            else
            {
                passwd.insert(curs, wd);
            }
        }
        for (auto& chr : passwd)
        {
            cout << chr;
        }
        cout << '\n';
    }

    return 0;
}