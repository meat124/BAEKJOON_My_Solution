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
        // ���� ���⿡�� �������� ȸ���ϸ鼭 û������ ���� ������ ã�� �����Ѵ�.
        for (int i = 0;i < 4;i++)
        {
            // ���� �ٶ󺸴� ���⿡�� �������� ȸ���� ����
            dir = (dir == 0) ? 3 : dir - 1;
            // �������� ȸ���� ������ ������ �ٶ󺸰�, ������ ������ �����ϰ�, ���� �ƴ϶��
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
            // �������� ȸ���� ������ ������ �ٶ󺸰�, ������ ������ �����ϰ�, ���� �ƴ϶��
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
            // �������� ȸ���� ������ ������ �ٶ󺸰�, ������ ������ �����ϰ�, ���� �ƴ϶��
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
            // �������� ȸ���� ������ ������ �ٶ󺸰�, ������ ������ �����ϰ�, ���� �ƴ϶��
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
        // �������� ��� ���⿡ û���� ������ �������� ����
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
        // �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ���
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
    map[a][b] = 2; // ���� ��ġ�� û���� ������ ǥ��
    result++;
    while (true)
    {
        if (!robot.Action_1())
            if (!robot.Action_3())
                break;
    }
    cout << result;
}