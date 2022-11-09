#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll result;
bool vis[2000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 2;i <= N;i++)
    {
        if (vis[i])
            continue;
        int mul = i;
        while (mul <= N)
        {
            if (vis[mul]) // 이미 방문했다면?
            {
                mul += i;
                continue;
            }
            // 방문하지 않았다면?
            vis[mul] = true;
            result += i;
            mul += i;
        }
    }
    cout << result;
}
