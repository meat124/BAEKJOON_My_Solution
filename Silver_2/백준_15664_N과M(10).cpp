#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N , M;
vector<int> vec;
vector<int> S;

void DFS(int start)
{
    if (S.size() == M)
    {
        for (auto i : S)
            cout << i << " ";
        cout << "\n";
        return;
    }
    int prev_num = -1;
    for (int i = start;i < N;i++)
    {
        if (prev_num == vec[i])
            continue;
        S.push_back(vec[i]);
        prev_num = vec[i];
        DFS(i + 1);
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