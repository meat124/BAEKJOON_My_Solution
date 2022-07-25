#include<iostream>
#include<vector>
#include<string>
using namespace std;
int N , M;
string N_str; // ���ϴ� ä�� string Ÿ��
int available_num[10]; // ���峭 ��ȣ�� 1�� ǥ��
string make_num;
int result = 50000000;

void Make_min_num()
{
    // �ڸ����� �������� result �� �� ���ϰ� ���� ������ �ʱ�ȭ �� �� ����
    if (make_num.length() == N_str.length())
    {
        int min_cnt = make_num.length() + abs(stoi(make_num) - N);
        result = result < min_cnt ? result : min_cnt;
        return;
    }
    for (int i = 0;i <= 9;i++)
    {
        // ���� ���峭 ��ư�̸� continue
        if (available_num[i] == 1)
            continue;
        make_num.push_back(i + 48);
        Make_min_num();
        make_num.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    N_str = to_string(N);
    cin >> M;
    for (int i = 0;i < M;i++)
    {
        int n;
        cin >> n;
        available_num[n] = 1;
    }
    // ����� ���� ���� ��, �� ���� N �� ���� ���Ѵ�.
    Make_min_num();
    vector<int> available;
    for (int i = 0;i < 10;i++)
    {
        if (available_num[i] == 0)
            available.push_back(i);
    }
    // �ڸ����� �ٸ� ������ �ּҰ��� ������ ��� ���� ó��
    if (!available.empty())
    {
        int min_num = available.front();
        int max_num = available.back();
        string tmp_min , tmp_max;
        for (int i = 0;i < N_str.length() + 1;i++)
            tmp_min += (min_num + 48);
        for (int i = 0;i < N_str.length() - 1;i++)
            tmp_max += (max_num + 48);
        // stoi() std::invalid_argument error
        try {
            int tmp = tmp_min.length() + abs(stoi(tmp_min) - N);
            result = result < tmp ? result : tmp;
            tmp = tmp_max.length() + abs(stoi(tmp_max) - N);
            result = result < tmp ? result : tmp;
        }
        catch (std::exception) {
            cout << result;
            return 0;
        }
    }
    result = result < abs(N - 100) ? result : abs(N - 100);
    cout << result;
}