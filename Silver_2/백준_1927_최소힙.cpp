#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<int , vector<int> , greater<int>> pq; // ÃÖ¼Ò Èü
int N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int op;
    while (N--)
    {
        cin >> op;
        if (op == 0)
            if (pq.empty())
                cout << "0\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        else
            pq.push(op);
    }
}