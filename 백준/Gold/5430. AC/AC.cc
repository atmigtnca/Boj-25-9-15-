#include <deque>
#include <iostream>
#include <string>
using namespace std;
using ll = long long;

void rstfnc(int sze, string& ipt, string& lst)
{
    int mode = 0;
    deque<int> rslt;

    for (int i = 0; i < lst.size(); i++)
    {
        if (lst[i] > '0' && lst[i] <= '9')
        {
            string num;
            int cur = i;
            while (1)
            {
                num += lst[cur];
                cur++;
                if (lst[cur] < '0' || lst[cur] > '9')
                {
                    i = --cur;
                    break;
                }
            }
            int push = stoi(num);
            rslt.push_back(push);
        }
    }

    for (size_t i = 0; i < ipt.size(); i++)
    {
        char cmd = ipt[i];
        if (cmd == 'R')
        {
            mode = mode == 0 ? 1 : 0;
        }
        else if (rslt.empty())
        {
            cout << "error" << '\n';
            return;
        }
        else
        {
            if (mode == 0)
            {
                rslt.pop_front();
            }
            else
            {
                rslt.pop_back();
            }
        }
    }

    int size = rslt.size();
    cout << '[';
    if (mode == 0)
    {
        for (int i = 0; i < size; i++)
        {
            cout << rslt[i];
            if (i + 1 != size)
            {
                cout << ',';
            }
        }
    }
    else
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << rslt[i];
            if (i != 0)
            {
                cout << ',';
            }
        }
    }

    cout << "]\n";
}

void iptfnc()
{
    int N, sze;
    string ipt, lst;
    cin >> N;

    while (N--)
    {
        cin >> ipt;
        cin >> sze;
        cin >> lst;
        rstfnc(sze, ipt, lst);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    iptfnc();

    return 0;
}