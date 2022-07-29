#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N , M;
vector<int> vec;
vector<int> S;
bool visit[10];

void DFS(int start)
{
    if (S.size() == M)
    {
        for (auto i : S)
            cout << i << " ";
        cout << "\n";
        return;
    }
    for (int i = start;i < N;i++)
    {
        if (visit[i])
            continue;
        visit[i] = true;
        S.push_back(vec[i]);
        DFS(i + 1);
        visit[i] = false;
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