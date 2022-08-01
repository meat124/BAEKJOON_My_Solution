#include<iostream>
#include<vector>
using namespace std;
int N , M , K;
int Notebook[50][50]; // ��Ʈ��
struct Sticker
{
    int column , row; // ��,�� ũ��
    int arr[11][11]; // ��ƼĿ ����(1�� �κ�)

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
vector<Sticker> stickers; // ��ƼĿ ���� ����
int result = 0;
// ���ڷ� �������� ��ƼĿ�� �޴´�.
// ��ƼĿ ���̱⿡ �����ϸ� true, �����ϸ� false �� �����Ѵ�.
bool Attach(Sticker& sticker , int column , int row)
{
    for (int i = 0;i < sticker.column;i++)
        for (int j = 0;j < sticker.row;j++)
            if (sticker.arr[i][j] == 1 && Notebook[i + column][j + row] == 1)
                return false;
    // ��ƼĿ ���̱� ����
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
// ��ƼĿ�� ���ڷ� �޾Ƽ� ���̴� �Լ�
void Attach_sticker(Sticker& sticker)
{
    // ��ƼĿ�� 4��ȸ���ذ��� ����
    for (int k = 0;k < 4;k++)
    {
        // (i,j) �� ���� �� ���� ��
        for (int i = 0;i < N - sticker.column + 1;i++)
            for (int j = 0;j < M - sticker.row + 1;j++)
            {
                // ������ �������� ��ƼĿ�� �ٿ���
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
    // ��ƼĿ �Է�
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
    // ��ƼĿ�� ���δ�.
    for (int i = 0;i < K;i++)
        Attach_sticker(stickers[i]);

    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            if (Notebook[i][j] == 1)
                result++;

    cout << result;
}