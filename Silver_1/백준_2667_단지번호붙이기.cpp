#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
queue<pair<int, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visit[27][27];
string board[27];
int total_group = 0;
vector<int> number_of_house;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> board[i];

    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
        {
            if (board[i][j] == '1' && visit[i][j] != true)
            {
                visit[i][j] = true;
                Q.push({i, j});
                total_group++;
                int cnt = 1;
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (size_t i = 0; i < 4; i++)
                    {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                            continue;
                        if (visit[nx][ny] || board[nx][ny] == '0')
                            continue;
                        visit[nx][ny] = true;
                        cnt++;
                        Q.push({nx, ny});
                    }
                }
                number_of_house.push_back(cnt);
            }
        }
    cout << total_group << "\n";
    sort(number_of_house.begin(), number_of_house.end());
    for (auto itr : number_of_house)
        cout << itr << "\n";
}