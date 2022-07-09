#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visit_time[200005];
queue<int> Q;
int dx[2] = {-1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    Q.push(N);
    visit_time[N] = 1;
    if (N == K)
    {
        cout << 0;
        return 0;
    }
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (size_t i = 0; i < 2; i++)
        {
            int nx = cur + dx[i];
            if (nx < 0 || nx > 100000)
                continue;
            if (visit_time[nx] != 0)
                continue;
            visit_time[nx] = visit_time[cur] + 1;
            if (nx == K)
            {
                cout << visit_time[nx] - 1;
                return 0;
            }
            Q.push(nx);
        }
        int nx = cur * 2;
        if (nx < 0 || nx > 100000)
            continue;
        if (visit_time[nx] != 0)
            continue;
        visit_time[nx] = visit_time[cur] + 1;
        if (nx == K)
        {
            cout << visit_time[nx] - 1;
            return 0;
        }
        Q.push(nx);
    }
}