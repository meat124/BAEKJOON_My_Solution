#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int T , n;
int arr[MAX];
bool vis[MAX];

void Input()
{
    cin >> n;
    // TC 가 여러 개 존재하는 문제에서는 항상 기존 변수들의 초기화에 유의한다.
    fill(arr , arr + n + 1 , 0);
    fill(vis , vis + n + 1 , false);
    for (int i = 1;i <= n;i++)
        cin >> arr[i];
}

int Solve()
{
    vector<int> path; // 학생들의 지목을 따라가며 경로를 저장할 컨테이너
    int result = 0;
    for (int i = 1;i <= n;i++)
    {
        path.clear();
        int j = i;
        // j 를 방문하지 않았다면 반복한다.
        while (!vis[j])
        {
            vis[j] = true;
            path.push_back(j);
            j = arr[j]; // j 번째 학생이 지목한 학생으로 j 를 다시 초기화함
        }
        // 여기 도착하면 j 는 방문한 상태에서 다시 방문한 것이다.
        auto st = find(path.begin() , path.end() , j); // j 가 있는 위치의 iterator 를 저장
        result += st - path.begin(); // 사이클이 시작하는 st 보다 앞에 있는 원소들은 사이클에 속하지 않는 것이므로 팀에 속하지 못한 것이다.
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        Input();
        cout << Solve() << "\n";
    }
}