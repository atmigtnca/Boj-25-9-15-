#include <iostream>
#include <stack>
#include <string>
using namespace std;
using ll = long long;
stack<char> mystack;
char cmpf[] = {'[', '('};
char cmpb[] = {']', ')'};

string check(string& ipt)
{
    for (int i = 0; i < ipt.length(); i++)
    {
        char alp = ipt[i];
        if (alp == '(' || alp == '[')
        {
            mystack.push(alp);
        }
        else if (alp == ')' || alp == ']')
        {
            bool chk = false;
            for (int j = 0; j < 2; j++)
            {
                if (!mystack.empty() && mystack.top() == cmpf[j] &&
                    alp == cmpb[j])
                {
                    mystack.pop();
                    chk = true;
                    break;
                }
            }
            if (!chk)
            {
                mystack.push(alp);
            }
        }
    }
    if (!mystack.size())
    {
        return "yes";
    }
    return "no";
}

void input()
{
    string ipt;
    while (1)
    {
        getline(cin, ipt);
        if (ipt == ".")
        {
            break;
        }
        int stacksze = mystack.size();
        while (stacksze--)
        {
            mystack.pop();
        }
        cout << check(ipt) << '\n';
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();

    return 0;
}