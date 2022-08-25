#include<iostream>
#include<vector>
using namespace std;
int T , N , M;
int DP[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        vector<int> coin;
        cin >> N;
        for (int i = 0;i < N;i++)
        {
            int c;
            cin >> c;
            coin.push_back(c);
        }
        cin >> M;
        fill(DP , DP + M + 1 , 0);
        DP[0] = 1;
        for (int i = 0;i < N;i++)
            for (int j = coin[i];j <= M;j++)
                DP[j] += DP[j - coin[i]];

        cout << DP[M] << "\n";
    }
}