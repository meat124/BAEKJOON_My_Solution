#include<bits/stdc++.h>
using namespace std;
vector<int> path;
int cache[5][5][100005];

void Input()
{
    int n;
    cin >> n;
    while (n)
    {
        path.push_back(n);
        cin >> n;
    }
}

int Move(int from , int to)
{
    if (from == to) // 같다면 1의 힘이 소모됨
        return 1;
    if (from == 0)
        return 2;
    if (from % 2 == 1)
        return to % 2 ? 4 : 3;
    else
        return to % 2 ? 3 : 4;
}

// 발의 위치가 {l,r} 이고 path[n] 을 밟았을 때, 소모되는 최소한의 힘
int Solve(int l , int r , int n)
{
    // 모든 발판을 다 밟으면 종료
    if (n == path.size())
        return 0;
    int& ret = cache[l][r][n]; // cache[l][r][n] 의 레퍼런스
    if (ret != 0)
        return ret;
    return ret = min(Move(l , path[n]) + Solve(path[n] , r , n + 1) ,
        Move(r , path[n]) + Solve(l , path[n] , n + 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    cout << Solve(0 , 0 , 0);
}