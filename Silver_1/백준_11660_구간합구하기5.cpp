#include<iostream>
using namespace std;
int N , M;
int board[1030][1030];
int area[1030][1030]; // (1,1) 기준으로 (i,j) 까지의 넓이

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
            cin >> board[i][j];
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
            area[i][j] = board[i][j] + area[i - 1][j] + area[i][j - 1] - area[i - 1][j - 1];
    while (M--)
    {
        int x1 , y1 , x2 , y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << area[x2][y2] - area[x1 - 1][y2] - area[x2][y1 - 1] + area[x1 - 1][y1 - 1] << "\n";
    }
}