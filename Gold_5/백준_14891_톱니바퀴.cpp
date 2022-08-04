#include<iostream>
#include<vector>
#include<deque>
#include<string>
using namespace std;
int K;
// 12�� ������ �ε��� 0, 3�� ������ �ε��� 2, 9�� ������ �ε��� 6
vector<deque<int>> Gears(5);
// �� �� ���� ȸ���ϴ��� �����ϴ� ����
vector<pair<int , int>> which_gear_rotate;

// ȸ���ϴ� ����� ��ȣ�� ������ �޾Ƽ� �� ������.
void Rotate_Gear()
{
    for (auto i : which_gear_rotate)
    {
        // �ð� �������� ȸ��
        if (i.second == 1)
        {
            int tmp = Gears[i.first].back();
            Gears[i.first].pop_back();
            Gears[i.first].push_front(tmp);
        }
        // �ݽð� �������� ȸ��
        else
        {
            int tmp = Gears[i.first].front();
            Gears[i.first].pop_front();
            Gears[i.first].push_back(tmp);
        }
    }
}
// ��� ��ȣ�� ȸ�� ������ ���ڷ� �޾Ƽ� ���� ���ư� ����� ������ Ǫ���Ѵ�.
void Find_Connected_Gear(int gear_num , int dir)
{
    which_gear_rotate.push_back({ gear_num, dir });
    int left_gear_num = gear_num - 1;
    int right_gear_num = gear_num + 1;
    int dir_tmp = dir;
    // �������� �̵�
    while (true)
    {
        if (left_gear_num < 1)
            break;
        if (Gears[left_gear_num][2] == Gears[left_gear_num + 1][6])
            break;
        which_gear_rotate.push_back({ left_gear_num, dir_tmp * (-1) });
        left_gear_num--;
        dir_tmp *= (-1);
    }
    dir_tmp = dir;
    // ���������� �̵�
    while (true)
    {
        if (right_gear_num > 4)
            break;
        if (Gears[right_gear_num][6] == Gears[right_gear_num - 1][2])
            break;
        which_gear_rotate.push_back({ right_gear_num, dir_tmp * (-1) });
        right_gear_num++;
        dir_tmp *= (-1);
    }
}

int Calculate_Gears_Point_Sum()
{
    // 12�� ������ ����
    int total_point = 0;
    for (int i = 1;i <= 4;i++)
        if (Gears[i][0] == 1)
            total_point += (1 << (i - 1));
    return total_point;
}

int main()
{
    for (int i = 1;i <= 4;i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0;j < 8;j++)
            Gears[i].push_back(tmp[j] - '0');
    }
    cin >> K;
    for (int i = 0;i < K;i++)
    {
        int n , dir;
        cin >> n >> dir;
        Find_Connected_Gear(n , dir);
        Rotate_Gear();
        which_gear_rotate.clear();
    }
    cout << Calculate_Gears_Point_Sum();
}