#include<iostream>
#include<vector>
using namespace std;
int N , M;
vector<pair<int , int>> house;
vector<pair<int , int>> chicken;
int arr[15][101]; // 각 행은 치킨집, 열은 집을 나타내고 값은 치킨집에서 집까지의 치킨거리를 나타낸다.
vector<int> chicken_select; // 남길 치킨집의 번호
int visit[15]; // 치킨집 방문 여부
int min_chicken_dis = 100000000;

int Find_total_chicken_distance()
{
    int total = 0;
    for (int i = 0;i < house.size();i++)
    {
        int min_dis = 1000000000;
        for (int j = 0;j < M;j++)
        {
            min_dis = min_dis < arr[chicken_select[j]][i] ? min_dis : arr[chicken_select[j]][i];
        }
        total += min_dis;
    }
    return total;
}

void DFS(int start)
{
    if (chicken_select.size() == M)
    {
        int cur_dis = Find_total_chicken_distance();
        min_chicken_dis = min_chicken_dis < cur_dis ? min_chicken_dis : cur_dis;
        return;
    }
    for (int i = start;i < chicken.size();i++)
    {
        if (visit[i])
            continue;
        chicken_select.push_back(i);
        visit[i] = true;
        DFS(i + 1);
        chicken_select.pop_back();
        visit[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
        {
            int n;
            cin >> n;
            if (n == 1)
                house.push_back({ i,j });
            else if (n == 2)
                chicken.push_back({ i,j });
        }
    for (int i = 0;i < chicken.size();i++)
        for (int j = 0;j < house.size();j++)
            arr[i][j] = abs(chicken[i].first - house[j].first) + abs(chicken[i].second - house[j].second);

    DFS(0);

    cout << min_chicken_dis;
}