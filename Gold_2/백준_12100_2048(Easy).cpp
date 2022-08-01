#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
struct Board
{
    int board[22][22];

    Board()
    {
        for (int i = 0;i < N;i++)
            for (int j = 0;j < N;j++)
                board[i][j] = 0;
    }
    Board(int arr[][22])
    {
        for (int i = 0;i < N;i++)
            for (int j = 0;j < N;j++)
                board[i][j] = arr[i][j];
    }
};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
Board init_board;
int max_result = 0;
vector<Board> board_vec;

int Find_max_num(Board& arr)
{
    int max_num = 0;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            max_num = max(max_num , arr.board[i][j]);
    return max_num;
}
bool OOB(int a , int b)
{
    return a < 0 || a >= N || b < 0 || b >= N;
}
// ���ڷ� ���� dir ���� ���� �����¿�� board �� �δ�.
void upd(int x , int y , int dir , Board& board)
{
    dir %= 4;
    while (true)
    {
        x += dx[dir];
        y += dy[dir];
        if (OOB(x , y) || board.board[x][y])
            return;
        board.board[x][y] = board.board[x - dx[dir]][y - dy[dir]];
        board.board[x - dx[dir]][y - dy[dir]] = 0;
    }
}
void Add_up(int dir , Board& board)
{
    int tmp_value;
    pair<int , int> tmp_coord;
    // �Ʒ�
    if (dir == 0)
        for (int row = 0;row < N;row++)
        {
            tmp_value = -1;
            for (int column = N - 1;column >= 0;column--)
            {
                if (board.board[column][row] == tmp_value)
                {
                    board.board[tmp_coord.first][tmp_coord.second] *= 2;
                    board.board[column][row] = 0;
                    tmp_value = -1;
                    continue;
                }
                if (board.board[column][row])
                {
                    tmp_value = board.board[column][row];
                    tmp_coord = { column, row };
                }
            }
        }
    // ������
    else if (dir == 1)
        for (int column = 0;column < N;column++)
        {
            tmp_value = -1;
            for (int row = N - 1; row >= 0;row--)
            {
                if (board.board[column][row] == tmp_value)
                {
                    board.board[tmp_coord.first][tmp_coord.second] *= 2;
                    board.board[column][row] = 0;
                    tmp_value = -1;
                    continue;
                }
                if (board.board[column][row])
                {
                    tmp_value = board.board[column][row];
                    tmp_coord = { column, row };
                }
            }
        }
    // ����
    else if (dir == 2)
        for (int row = 0;row < N;row++)
        {
            tmp_value = -1;
            for (int column = 0; column < N;column++)
            {
                if (board.board[column][row] == tmp_value)
                {
                    board.board[tmp_coord.first][tmp_coord.second] *= 2;
                    board.board[column][row] = 0;
                    tmp_value = -1;
                    continue;
                }
                if (board.board[column][row])
                {
                    tmp_value = board.board[column][row];
                    tmp_coord = { column, row };
                }
            }
        }
    // ����
    else if (dir == 3)
        for (int column = 0;column < N;column++)
        {
            tmp_value = -1;
            for (int row = 0; row < N;row++)
            {
                if (board.board[column][row] == tmp_value)
                {
                    board.board[tmp_coord.first][tmp_coord.second] *= 2;
                    board.board[column][row] = 0;
                    tmp_value = -1;
                    continue;
                }
                if (board.board[column][row])
                {
                    tmp_value = board.board[column][row];
                    tmp_coord = { column, row };
                }
            }
        }
}
// �а� Board �� �����Ѵ�.
Board Push_board(int dir , Board board)
{
    Add_up(dir , board);
    // �Ʒ� or ���������� �б�
    if (dir == 0 || dir == 1)
        for (int i = N - 1;i >= 0;i--)
            for (int j = N - 1;j >= 0;j--)
                upd(i , j , dir , board);
    // �� or �������� �б�
    else if (dir == 2 || dir == 3)
        for (int i = 0;i < N;i++)
            for (int j = 0;j < N;j++)
                upd(i , j , dir , board);
    return board;
}

void DFS(int level)
{
    if (level == 5)
    {
        max_result = max(max_result , Find_max_num(board_vec.back()));
        return;
    }
    // ���� ���带 �����¿�� �̵�
    // i == 0 > �Ʒ��� �̵�, i == 1 > ���������� �̵�, i == 2 > ���� �̵�, i == 3 > �������� �̵�
    for (int i = 0;i < 4;i++)
    {
        board_vec.push_back(Push_board(i , board_vec.back()));
        DFS(level + 1);
        board_vec.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            cin >> init_board.board[i][j];
    board_vec.push_back(init_board);

    DFS(0);

    cout << max_result;
}