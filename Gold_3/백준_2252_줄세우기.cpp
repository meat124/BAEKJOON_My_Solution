#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N , M;
vector<int> adj[32005];
vector<int> result; // 위상 정렬 결과
int deg[32005]; // indegree 개수
queue<int> Q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    while (M--)
    {
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    // indegree == 0 인 학생 큐에 푸시
    for (int i = 1;i <= N;i++)
        if (deg[i] == 0)
            Q.push(i);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        result.push_back(cur);
        for (int nxt : adj[cur])
        {
            deg[nxt]--;
            if (deg[nxt] == 0)
                Q.push(nxt);
        }
    }
    for (int i : result)
        cout << i << " ";
}