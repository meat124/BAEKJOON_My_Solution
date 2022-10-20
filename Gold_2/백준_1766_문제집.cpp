#include<bits/stdc++.h>
using namespace std;
int N , M;
int indeg[32005];
vector<int> order;
vector<int> adj[32005];

void Solve()
{
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 1;i <= N;i++)
        if (indeg[i] == 0)
            pq.push(i);
    // 단순히 먼저 푸는 것이 아닌, 난이도도 생각하여 풀어야 한다.
    // 만약 indeg 가 0이 되었다면, 그 상황에서 그 문제의 난이도가 어떠할지 예측이 불가하다.
    // 따라서 그 문제의 난이도에 진입차수가 0이 된 상황에서는 큐에 존재하는 어떠한 문제들도
    // 현재 문제를 푸는데 영향을 미치지 못한다.
    // 따라서 그 상황에서는 그 문제를 난이도가 적절한 위치에 넣는 것이 맞다.
    // 따라서 우선순위 큐에는 우선순위를 문제의 번호로 넣어주고 정렬해서 푼다.
    // 즉 우선순위 큐에는 indeg 가 0인 문제만 존재한다.
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        cout << cur << " ";
        for (auto i : adj[cur])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                pq.push(i);
        }
    }
}

void Input()
{
    cin >> N >> M;
    for (int i = 0;i < M;i++)
    {
        int a , b;
        cin >> a >> b;
        indeg[b]++; // b 번 문제의 진입차수를 1 증가시킴
        adj[a].push_back(b);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 위상 정렬?
    // 문제들 간의 우선순위를 정한 뒤, 
    Input();
    Solve();
}