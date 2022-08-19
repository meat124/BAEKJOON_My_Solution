#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N , M;
vector<int> adj_lighter[105]; // 자신보다 가벼운 구슬에 대한 인접리스트
vector<int> adj_heavier[105]; // 자신보다 무거운 구슬에 대한 인접리스트
bool visit[105];
queue<int> Q;
int result = 0;

// 무게가 중간인 구슬이 될 수 없는 무게가 무거운 구슬을 찾는 BFS
bool BFS_min(int start)
{
    int cnt = 0;
    Q.push(start);
    visit[start] = true;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (auto nxt : adj_lighter[cur])
        {
            if (visit[nxt])
                continue;
            visit[nxt] = true;
            Q.push(nxt);
            cnt++;
        }
    }
    // 만약 중간 구슬이 될 수 없는 무거운 구슬이라면 true 리턴
    if (cnt > N / 2)
        return true;
    return false;
}

// 무게가 중간인 구슬이 될 수 없는 무게가 가벼운 구슬을 찾는 BFS
bool BFS_max(int start)
{
    int cnt = 0;
    Q.push(start);
    visit[start] = true;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (auto nxt : adj_heavier[cur])
        {
            if (visit[nxt])
                continue;
            visit[nxt] = true;
            Q.push(nxt);
            cnt++;
        }
    }
    // 만약 중간 구슬이 될 수 없는 가벼운 구슬이라면 true 리턴
    if (cnt > N / 2)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    while (M--)
    {
        int a , b;
        cin >> a >> b;
        // a번 구슬보다 가벼운 구슬 b
        adj_lighter[a].push_back(b);
        // b번 구슬보다 무거운 구슬 a
        adj_heavier[b].push_back(a);
    }
    for (int i = 1;i <= N;i++)
    {
        if (BFS_min(i))
            result++;
        fill(visit , visit + 105 , false);
        if (BFS_max(i))
            result++;
        fill(visit , visit + 105 , false);
    }
    cout << result;
}