#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;
// first : 절댓값, second : 실제값
priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
// 11286 절댓값 힙
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
        {
            if (pq.empty())
                cout << "0\n";
            else
            {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
        else
            pq.push({ abs(op), op });
    }
}