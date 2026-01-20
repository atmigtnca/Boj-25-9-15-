#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int heap[100005];
int sze = 0;
int n;

void push(int x)
{
    heap[++sze] = x;
    int idx = sze;
    while (idx != 1)
    {
        int par = idx / 2;
        if (heap[par] <= heap[idx])
        {
            break;
        }
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

int top() { return heap[1]; }

void pop()
{
    heap[1] = heap[sze--];
    int idx = 1;
    while (2 * idx <= sze)
    {
        int lc = 2 * idx, rc = 2 * idx + 1;
        int min_child = lc;
        if (rc <= sze && heap[rc] < heap[lc])
        {
            min_child = rc;
        }
        if (heap[idx] <= heap[min_child])
        {
            break;
        }
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}

void input()
{
    int ipt;
    cin >> n;
    while (n--)
    {
        cin >> ipt;
        if (ipt == 0)
        {
            if (!sze)
            {
                cout << 0 << '\n';
                continue;
            }
            cout << top() << '\n';
            pop();
        }
        else
        {
            push(ipt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();

    return 0;
}
