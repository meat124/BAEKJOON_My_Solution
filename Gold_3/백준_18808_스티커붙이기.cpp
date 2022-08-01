#include<iostream>
#include<vector>
using namespace std;
int N , M , K;
int Notebook[50][50]; // 노트북
struct Sticker
{
    int column , row; // 행,열 크기
    int arr[11][11]; // 스티커 형태(1인 부분)

    Sticker(int column , int row) : column(column) , row(row)
    {
        for (int i = 0;i < column;i++)
            for (int j = 0;j < row;j++)
                arr[i][j] = 0;
    }
    Sticker(int column , int row , int a[11][11]) : column(column) , row(row)
    {
        for (int i = 0;i < column;i++)
            for (int j = 0;j < row;j++)
                arr[i][j] = a[i][j];
    }
};
vector<Sticker> stickers; // 스티커 보관 벡터
int result = 0;
// 인자로 기준점과 스티커를 받는다.
// 스티커 붙이기에 성공하면 true, 실패하면 false 를 리턴한다.
bool Attach(Sticker& sticker , int column , int row)
{
    for (int i = 0;i < sticker.column;i++)
        for (int j = 0;j < sticker.row;j++)
            if (sticker.arr[i][j] == 1 && Notebook[i + column][j + row] == 1)
                return false;
    // 스티커 붙이기 가능
    for (int i = 0;i < sticker.column;i++)
        for (int j = 0;j < sticker.row;j++)
            if (sticker.arr[i][j] == 1 && Notebook[i + column][j + row] == 0)
                Notebook[i + column][j + row] = 1;
    return true;
}
Sticker Rotate_sticker(Sticker& sticker)
{
    Sticker tmp_sticker(sticker.row , sticker.column);

    for (int i = 0;i < sticker.column;i++)
        for (int j = 0;j < sticker.row;j++)
        {
            if (sticker.arr[i][j] == 1)
                tmp_sticker.arr[j][sticker.column - i - 1] = 1;
        }

    return tmp_sticker;
}
// 스티커를 인자로 받아서 붙이는 함수
void Attach_sticker(Sticker& sticker)
{
    // 스티커를 4번회전해가며 붙임
    for (int k = 0;k < 4;k++)
    {
        // (i,j) 는 왼쪽 위 기준 점
        for (int i = 0;i < N - sticker.column + 1;i++)
            for (int j = 0;j < M - sticker.row + 1;j++)
            {
                // 기준점 기준으로 스티커를 붙여봄
                if (Attach(sticker , i , j))
                    return;
            }
        sticker = Rotate_sticker(sticker);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    // 스티커 입력
    for (int i = 0;i < K;i++)
    {
        int arr_tmp[11][11];
        int col_tmp , row_tmp;
        cin >> col_tmp >> row_tmp;
        for (int j = 0;j < col_tmp;j++)
            for (int k = 0;k < row_tmp;k++)
                cin >> arr_tmp[j][k];
        Sticker sticker(col_tmp , row_tmp , arr_tmp);
        stickers.push_back(sticker);
    }
    // 스티커를 붙인다.
    for (int i = 0;i < K;i++)
        Attach_sticker(stickers[i]);

    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            if (Notebook[i][j] == 1)
                result++;

    cout << result;
}