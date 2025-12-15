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
Person old_person = {"OLD", 99, 99, 9999};
Person young_person = {"YOUNG", 0, 0, 0};

bool isOlder(const Person& a, const Person& b)
{
    if (a.year != b.year)
    {
        return a.year < b.year;
    }
    if (a.month != b.month)
    {
        return a.month < b.month;
    }
    return a.day < b.day;
}

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
    if (isOlder(young_person, in))
    {
        young_person = in;
    }
    if (isOlder(in, old_person))
    {
        old_person = in;
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