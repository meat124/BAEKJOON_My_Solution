#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N , K , M;
vector<int> hypertube[1005]; // 하이퍼 튜브의 역 번호
vector<int> station[100005]; // 역의 하이퍼 튜브 번호
bool visit[100005];
bool visit_h[1005];
int min_cnt = -1;

void BFS()
{
    queue<pair<int , int>> Q; // first : 역 번호, second : 걸린 최소 역 개수
    Q.push({ 1,1 });
    visit[1] = true;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (auto nxt_h : station[cur.first]) // 하이퍼 튜브 순회
        {
            if (visit_h[nxt_h])
                continue;
            visit_h[nxt_h] = true;
            for (auto nxt_s : hypertube[nxt_h]) // 역 순회
            {
                if (visit[nxt_s])
                    continue;
                if (nxt_s == N)
                {
                    min_cnt = cur.second + 1;
                    return;
                }
                visit[nxt_s] = true;
                Q.push({ nxt_s, cur.second + 1 });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K >> M;
    for (int i = 0;i < M;i++)
    {
        for (int j = 0;j < K;j++)
        {
            int n;
            cin >> n;
            hypertube[i].push_back(n);
            station[n].push_back(i);
        }
    }
    if (N == 1)
    {
        cout << 1;
        return 0;
    }
    BFS();
    cout << min_cnt;
}