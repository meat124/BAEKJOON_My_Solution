#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N , M;
vector<int> D;
bool disability_num[10];

// ���ڷ� ���� ���ڿ� ��� �Ұ����� ��ȣ�� �ִٸ� false, ���ٸ� true �� �����ϴ� �Լ�
bool Check(int cur)
{
    string s_cur = to_string(cur); // ���� Ž���ϰ� �ִ� ��ȣ�� string ���� ĳ����

    for (int i = 0;i < s_cur.length();i++)
        if (disability_num[s_cur[i] - '0']) // ��ȣ�� ���峭 ��ȣ�� �� �ִٸ�
            return false; // false �� �����Ѵ�.
    return true; // ���峭 ��ȣ�� ���ٸ� true �� �����Ѵ�.
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    int tmp;
    for (int i = 0;i < M;i++)
    {
        cin >> tmp;
        disability_num[tmp] = true; // ��� �Ұ��� ��ȣ true �� �ʱ�ȭ
    }

    string str_N = to_string(N);

    int min_cnt = abs(N - 100); // 100���� �̵��ϴ� Ƚ���� ���۰����� ����

    // 0 ���� 10^6���� ��� ���� ���� ��츦 ����Ͽ� �ּ� �̵� Ƚ���� Ž���Ѵ�.
    for (int i = 0;i <= 1000000;i++)
    {
        if (Check(i)) // ���� ���峭 ��ȣ�� ���ٸ� �ּҰ��� ����Ѵ�.
        {
            // N ������ 1�� �̵� Ƚ�� + ���� i �� �Է��ϴµ� �ʿ��� Ƚ��
            tmp = abs(N - i) + to_string(i).length();
            min_cnt = min(min_cnt , tmp);
        }
        // i �� ���峭 ��ȣ�� �ִٸ� �� ��ȣ�� ī��Ʈ �� �ʿ䰡 ����.
    }

    cout << min_cnt;
}