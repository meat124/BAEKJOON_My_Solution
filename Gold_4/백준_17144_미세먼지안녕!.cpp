#include<bits/stdc++.h>
using namespace std;
int R , C , T;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<int>> A(55 , vector<int>(55));
vector<vector<bool>> dust(55 , vector<bool>(55)); // 미세먼지가 있는 곳을 true 로 표시
vector<pair<int , int>> air_cleaner;

template<typename T>
void Copy_Arr(T& start , T& dest)
{
    for (int i = 0;i < R;i++)
        for (int j = 0;j < C;j++)
            dest[i][j] = start[i][j];
}

bool OOB(pair<int , int> a)
{
    if (a.first < 0 || a.first >= R || a.second < 0 || a.second >= C)
        return true;
    if (A[a.first][a.second] == -1)
        return true;
    return false;
}

void Wind(int dir , pair<int , int> start , bool upper)
{
    pair<int , int> prev_c = start , next_c = { start.first + dx[dir], start.second + dy[dir] };
    while (true)
    {
        if (OOB(next_c))
            break;
        if (upper && next_c.first > air_cleaner[0].first)
            break;
        if (!upper && next_c.first < air_cleaner[1].first)
            break;
        A[prev_c.first][prev_c.second] = A[next_c.first][next_c.second];
        A[next_c.first][next_c.second] = 0;
        dust[prev_c.first][prev_c.second] = dust[next_c.first][next_c.second];
        prev_c = next_c;
        next_c.first += dx[dir];
        next_c.second += dy[dir];
    }
}

void Clean()
{
    // upper clean
    A[air_cleaner[0].first - 1][air_cleaner[0].second] = 0;
    Wind(2 , { air_cleaner[0].first - 1, 0 } , true);
    Wind(1 , { 0, 0 } , true);
    Wind(0 , { 0,C - 1 } , true);
    Wind(3 , { air_cleaner[0].first, C - 1 } , true);
    // lower clean
    A[air_cleaner[1].first + 1][air_cleaner[1].second] = 0;
    Wind(0 , { air_cleaner[1].first + 1, 0 } , false);
    Wind(1 , { R - 1, 0 } , false);
    Wind(2 , { R - 1, C - 1 } , false);
    Wind(3 , { air_cleaner[1].first, C - 1 } , false);
}

void Diffusion()
{
    vector<vector<int>> tmp_A(55 , vector<int>(55 , 0));
    Copy_Arr(A , tmp_A);
    vector<vector<bool>> tmp_dust(55 , vector<bool>(55 , false));
    for (int i = 0;i < R;i++)
        for (int j = 0;j < C;j++)
        {
            // 미세먼지가 없다면 continue
            if (!dust[i][j])
                continue;
            tmp_dust[i][j] = true;
            int n = A[i][j] / 5; // 확산되는 미세먼지의 양
            // 확산되는 미세먼지가 0이라면 continue
            if (n == 0)
                continue;
            int cnt = 0; // 확산된 방향의 개수
            for (int k = 0;k < 4;k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (OOB({ nx,ny }))
                    continue;
                // 공기청정기가 있는 구역은 continue
                if (A[nx][ny] == -1)
                    continue;
                tmp_A[nx][ny] += n;
                tmp_dust[nx][ny] = true; // 확산된 구역을 미세먼지 존재하는 것으로 표시
                cnt++; // 확산된 방향 개수 증가
            }
            tmp_A[i][j] -= n * cnt; // 확산된 방향 개수 * 확산된 양 을 기존의 미세먼지 구역에서 빼줌
        }
    Copy_Arr(tmp_A , A);
    Copy_Arr(tmp_dust , dust);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C >> T;
    for (int i = 0;i < R;i++)
        for (int j = 0;j < C;j++)
        {
            cin >> A[i][j];
            if (A[i][j] == -1)
                air_cleaner.push_back({ i,j });
            if (A[i][j] > 0)
                dust[i][j] = true;
        }
    while (T--)
    {
        Diffusion();
        Clean();
    }
    int result = 0;
    for (int i = 0;i < R;i++)
        for (int j = 0;j < C;j++)
            if (A[i][j] > 0)
                result += A[i][j];
    cout << result;
}