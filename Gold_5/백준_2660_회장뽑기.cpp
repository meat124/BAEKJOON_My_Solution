#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;
vector<int> adj[60];
queue<pair<int , int>> Q; // first : 회원 번호, second : 깊이
int point[60];
bool visit[60];
int min_point = 0x7FFFFFFF;

void BFS(int start)
{
    Q.push({ start, 0 });
    visit[start] = true;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (auto nxt : adj[cur.first])
        {
            if (visit[nxt])
                continue;
            visit[nxt] = true;
            Q.push({ nxt, cur.second + 1 });
            point[start] = cur.second + 1;
        }
    }
    min_point = min(min_point , point[start]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int a , b;
    while (true)
    {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1;i <= N;i++)
    {
        BFS(i);
        fill(visit , visit + 60 , false);
    }
    cout << min_point << " " << count(point , point + 60 , min_point) << "\n";
    for (int i = 1;i <= N;i++)
        if (point[i] == min_point)
            cout << i << " ";

}