#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T , N;
double result = 0x7FFFFFFF;
vector<pair<int , int>> coord;

void Solve()
{
    vector<int> combi;
    for (int i = 0;i < N / 2;i++)
        combi.push_back(0);
    for (int i = 0;i < N / 2;i++)
        combi.push_back(1);

    int sum_x = 0 , sum_y = 0;
    for (auto i : coord)
    {
        sum_x += i.first;
        sum_y += i.second;
    }
    do
    {
        ll cur_x = sum_x , cur_y = sum_y;
        for (int i = 0;i < N;i++)
            if (!combi[i])
            {
                cur_x -= 2 * coord[i].first;
                cur_y -= 2 * coord[i].second;
            }
        result = min(result , sqrt(cur_x * cur_x + cur_y * cur_y));
    } while (next_permutation(combi.begin() , combi.end()));
}


void Input()
{
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        int x , y;
        cin >> x >> y;
        coord.push_back({ x,y });
    }
}

// TLE occur
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        Input();
        Solve();
        cout << fixed;
        cout.precision(7); // 오차 10^-6 까지 허용이므로
        cout << result << "\n";
        // for next TC
        coord.clear();
        result = 0x7FFFFFFF;
    }
}