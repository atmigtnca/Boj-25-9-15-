#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int A[51];
int B[51];

bool down(int i, int j) { return (i > j); }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + N, down);

    int MIN = 0;
    for (int i = 0; i < N; i++)
    {
        MIN += A[i] * B[i];
    }

    cout << MIN << '\n';

    return 0;
}