#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool fml(const string &a, const string &b)
{
    return a.size() < b.size();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> word(n);

    for (size_t i = 0; i < word.size(); ++i)
    {
        cin >> word[i];
    }

    sort(word.begin(), word.end());
    stable_sort(word.begin(), word.end(), fml);

    word.erase(unique(word.begin(), word.end()), word.end());

    for (size_t i = 0; i < word.size(); ++i)
    {
        cout << word[i] << '\n';
    }

    return 0;
}