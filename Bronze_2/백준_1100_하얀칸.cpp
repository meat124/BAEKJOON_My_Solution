#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> board;
    for (int i = 0;i < 8;i++)
    {
        string str;
        cin >> str;
        board.push_back(str);
    }
    int result = 0;
    for (int i = 0;i < 8;i++)
        for (int j = 0;j < 8;j++)
        {
            if (board[i][j] == 'F' && (i + j) % 2 == 0)
                result++;
        }
    cout << result;
}