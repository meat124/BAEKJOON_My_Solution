#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N , M;
vector<int> vec;
vector<int> S;

void DFS(int level)
{
    if (level == M)
    {
        for (auto i : S)
            cout << i << " ";
        cout << "\n";
        return;
    }
    for (int i = 0;i < N;i++)
    {
        S.push_back(vec[i]);
        DFS(level + 1);
        S.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0;i < N;i++)
    {
        int n;
        cin >> n;
        vec.push_back(n);
    }
    sort(vec.begin() , vec.end());
    DFS(0);
}