#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<pair<int , int>> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        pair<int , int> p;
        cin >> p.first >> p.second;
        vec.push_back(p);
    }
    sort(vec.begin() , vec.end());
    auto cur = vec[0];
    int max_cnt = 1;
    for (int i = 1;i < N;i++)
    {
        if (cur.first < vec[i].first && cur.second > vec[i].second)
            cur = vec[i];
        else if (cur.second <= vec[i].first)
        {
            cur = vec[i];
            max_cnt++;
        }
    }
    cout << max_cnt;
}