#include<iostream>
using namespace std;
int N;
int board[150][150];
int result[2]; // result[0] 은 하얀색 색종이의 개수, result[1] 은 파란색 색종이의 개수

void Cut_Board(pair<int , int> start , pair<int , int> end , int n)
{
    if (n == 1)
    {
        result[board[start.first][start.second]]++;
        return;
    }
    int color[2] = { 0, 0 }; // color[0] 은 하얀색 색종이의 개수, color[1] 은 파란색 색종이의 개수
    for (int i = start.first;i <= end.first;i++)
        for (int j = start.second;j <= end.second;j++)
            color[board[i][j]]++;
    if (color[0] != 0 && color[1] != 0)
    {
        int mid_row = (start.first + end.first) / 2;
        int mid_col = (start.second + end.second) / 2;
        Cut_Board(start , { mid_row, mid_col } , n / 2);
        Cut_Board({ start.first,mid_col + 1 } , { mid_row, end.second } , n / 2);
        Cut_Board({ mid_row + 1, start.second } , { end.first, mid_col } , n / 2);
        Cut_Board({ mid_row + 1, mid_col + 1 } , end , n / 2);
    }
    else
    {
        result[board[start.first][start.second]]++;
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            cin >> board[i][j];
    // 시작점과 종료점을 매개변수로 선언한다.
    // 그 구간에 대해서 탐색을 진행한다.
    // 만약 모두 1, 또는 0으로 이루어져 있지 않다면 다시 자른다.
    Cut_Board({ 0,0 } , { N - 1,N - 1 } , N);
    cout << result[0] << "\n" << result[1];
}