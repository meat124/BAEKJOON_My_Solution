#include<iostream>
using namespace std;
int N , M;
int map[51][51];
int result = 0;

class Robotic_Vacuum
{
    int column , row;
    int dir;

public:
    Robotic_Vacuum(int column , int row , int dir) : column(column) , row(row) , dir(dir) {}

    bool Action_1()
    {
        // 현재 방향에서 왼쪽으로 회전하면서 청소하지 않은 방향을 찾아 전진한다.
        for (int i = 0;i < 4;i++)
        {
            // 현재 바라보는 방향에서 왼쪽으로 회전한 방향
            dir = (dir == 0) ? 3 : dir - 1;
            // 왼쪽으로 회전한 방향이 북쪽을 바라보고, 북쪽의 공간이 존재하고, 벽이 아니라면
            if (dir == 0 && column - 1 > 0 && map[column - 1][row] == 0)
            {
                column--;
                if (map[column][row] != 2)
                {
                    map[column][row] = 2;
                    result++;
                }
                return true;
            }
            // 왼쪽으로 회전한 방향이 동쪽을 바라보고, 동쪽의 공간이 존재하고, 벽이 아니라면
            else if (dir == 1 && row + 1 < M - 1 && map[column][row + 1] == 0)
            {
                row++;
                if (map[column][row] != 2)
                {
                    map[column][row] = 2;
                    result++;
                }
                return true;
            }
            // 왼쪽으로 회전한 방향이 남쪽을 바라보고, 남쪽의 공간이 존재하고, 벽이 아니라면
            else if (dir == 2 && column < N - 1 && map[column + 1][row] == 0)
            {
                column++;
                if (map[column][row] != 2)
                {
                    map[column][row] = 2;
                    result++;
                }
                return true;
            }
            // 왼쪽으로 회전한 방향이 서쪽을 바라보고, 서쪽의 공간이 존재하고, 벽이 아니라면
            else if (dir == 3 && row - 1 > 0 && map[column][row - 1] == 0)
            {
                row--;
                if (map[column][row] != 2)
                {
                    map[column][row] = 2;
                    result++;
                }
                return true;
            }
        }
        // 동서남북 모든 방향에 청소할 공간이 존재하지 않음
        return false;
    }
    bool Action_3()
    {
        if (dir == 0 && column + 1 < N - 1 && map[column + 1][row] != 1)
        {
            column++;
            return true;
        }
        else if (dir == 1 && row - 1 > 0 && map[column][row - 1] != 1)
        {
            row--;
            return true;
        }
        else if (dir == 2 && column - 1 > 0 && map[column - 1][row] != 1)
        {
            column--;
            return true;
        }
        else if (dir == 3 && row + 1 < M - 1 && map[column][row + 1] != 1)
        {
            row++;
            return true;
        }
        // 네 방향 모두 청소가 이미 되어있거나 벽인 경우
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    int a , b , c;
    cin >> a >> b >> c;
    Robotic_Vacuum robot(a , b , c);

    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            cin >> map[i][j];
    map[a][b] = 2; // 시작 위치를 청소한 것으로 표시
    result++;
    while (true)
    {
        if (!robot.Action_1())
            if (!robot.Action_3())
                break;
    }
    cout << result;
}