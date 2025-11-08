#include <iostream>
#include <list>
#include <string>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<string> memo;

    string input;
    cin >> input;
    for (auto& chr : input)
    {
        memo.push_back({chr});  // 각각 list에 추가
    }

    int count;
    cin >> count;

    auto it = memo.end();  // 커서생성

    while (count--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "L")  // 커서를 왼쪽으로 한 칸 옮김
        {
            if (it != memo.begin())  // 커서가 문장의 맨 앞이면 무시됨
            {
                it--;
            }
        }
        else if (cmd == "D")  // 커서를 오른쪽으로 한 칸 옮김
        {
            if (it != memo.end())  // 커서가 문장의 맨 뒤이면 무시됨
            {
                it++;
            }
        }
        else if (cmd == "B")  // 커서 왼쪽에 있는 문자를 삭제함
        {
            if (it != memo.begin())  // 커서가 문장의 맨 앞이면 무시됨
            {
                it--;
                it = memo.erase(it);
            }
        }
        else if (cmd == "P")  // 문자를 커서 왼쪽에 추가함
        {
            string n;
            cin >> n;
            memo.insert(it, n);
        }
    }

    for (auto& chr : memo)  // 최종출력
    {
        cout << chr;
    }
    cout << '\n';

    return 0;
}