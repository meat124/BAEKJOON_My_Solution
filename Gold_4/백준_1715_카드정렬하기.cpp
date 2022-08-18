#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N;
priority_queue<int , vector<int> , greater<int>> pq;
int total_cmp = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    while (N--)
    {
        int n;
        cin >> n;
        pq.push(n);
    }
    while (pq.size() != 1)
    {
        int tmp1 = pq.top();
        pq.pop();
        int tmp2 = pq.top();
        pq.pop();
        total_cmp += (tmp1 + tmp2);
        pq.push(tmp1 + tmp2);
    }
    cout << total_cmp;
}