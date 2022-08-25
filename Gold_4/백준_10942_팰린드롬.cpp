#include<iostream>
#include<vector>
using namespace std;
int N , M;
int board[2005];
vector<pair<int , int>> range;
bool DP[2005][2005]; // DP[i][j] 는 i-j의 수열이 펠린드롬인지 판단한다.
// 어떤 펠린드롬 수의 양옆에 같은 수가 추가되면 그 수는 펠린드롬이다.
// 기본적으로 DP[a][a] = true 이다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1;i <= N;i++)
        cin >> board[i];
    cin >> M;
    for (int i = 0;i < M;i++)
    {
        int S , E;
        cin >> S >> E;
        range.push_back({ S,E });
    }
    for (int i = 1;i <= N;i++)
        DP[i][i] = true;
    for (int i = N;i >= 1;i--)
        for (int j = 1;j <= N;j++)
        {
            if (DP[i][j])
                continue;
            if (j - i == 1 && board[i] == board[j])
                DP[i][j] = true;
            else if (j - i > 1 && DP[i + 1][j - 1] && board[i] == board[j])
                DP[i][j] = true;
        }
    for (auto r : range)
        cout << DP[r.first][r.second] << "\n";
}