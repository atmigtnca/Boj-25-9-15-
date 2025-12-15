#include <iostream>
#include <string>
using namespace std;
using ll = long long;

struct Person
{
    string name;
    int day;
    int month;
    int year;
};
Person old_person = {"OLD", 13, 32, 2011};
Person young_person = {"YOUNG", 0, 0, 1989};

Person fndfnc()
{
    Person out;
    cin >> out.name;
    cin >> out.day;
    cin >> out.month;
    cin >> out.year;

    return out;
}

void cmpfnc(Person& in)
{
    if (in.year > young_person.year)
    {
        young_person = in;
    }
    else if (in.year == young_person.year)
    {
        if (in.month > young_person.month)
        {
            young_person = in;
        }
        else if (in.month == old_person.month && in.day > young_person.day)
        {
            young_person = in;
        }
    }

    if (in.year < old_person.year)
    {
        old_person = in;
    }
    else if (in.year == old_person.year)
    {
        if (in.month < old_person.month)
        {
            old_person = in;
        }
        else if (in.month == old_person.month && in.day < old_person.day)
        {
            old_person = in;
        }
    }
}

void rstfnc()
{
    int N;
    cin >> N;

    while (N--)
    {
        Person in = fndfnc();
        cmpfnc(in);
    }

    cout << young_person.name << '\n';
    cout << old_person.name << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    rstfnc();

    return 0;
}