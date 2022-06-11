#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Self_Number(int n, vector<int> &vec)
{
    // n ���� �����ؼ� ����ؼ� ������ ����鼭 �� ������ ���Ϳ��� �����Ѵ�.
    // ���Ϳ��� �����Ѵٴ� �ǹ̴� �� ���� ���� �ε����� ���� 1�� �ʱ�ȭ ��Ű�� ���̴�.

    int d_n = n;
    string str_n = to_string(n);
    for (int i = 0; i < str_n.size(); i++)
    {
        d_n += (str_n[i] - 48);
    }
    if (d_n <= 10000)
    {
        vec[d_n] = 1;
        Self_Number(d_n, vec);
    }
    else
        return;
}

int main()
{
    vector<int> int_vec(10001); // int Ÿ�� ���� ���� �� ��� ��Ҹ� 0���� �ʱ�ȭ

    for (int i = 1; i <= 10000; i++)
    {
        if (int_vec[i] == 1)
            continue;
        Self_Number(i, int_vec);
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (int_vec[i] == 0)
            cout << i << endl;
    }
}