#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int N;
int arr[21][21];
vector<int> t1 , t2;
bool visit[21];
int min_stat_dif = 0;

// 인자로 전달 받은 팀원의 번호로 팀의 능력치를 구해 리턴
int total_point(vector<int>& team)
{
    int sum = 0;
    for (auto first : team)
        for (auto second : team)
            sum += arr[first][second];
    return sum;

}
void make_team(int level , int start)
{
    if (level == N / 2)
    {
        t2.clear();
        for (int i = 0;t2.size() < (N / 2);i++)
        {
            if (visit[i])
                continue;
            t2.push_back(i);
        }
        int dif = abs(total_point(t1) - total_point(t2));
        min_stat_dif = min_stat_dif < dif ? min_stat_dif : dif;
        return;
    }
    for (int i = start;t1.size() < (N / 2);i++)
    {
        if (visit[i])
            continue;
        if (i > N - 1)
            break;
        t1.push_back(i);
        visit[i] = true;
        make_team(level + 1 , i + 1);
        t1.pop_back();
        visit[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
        {
            cin >> arr[i][j];
            min_stat_dif += arr[i][j];
        }
    make_team(0 , 0);
    cout << min_stat_dif;
}