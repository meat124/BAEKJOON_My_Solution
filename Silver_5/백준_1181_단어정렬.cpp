#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(string a, string b)
{
    return a.length() < b.length();
}

bool compare_lib(string a, string b)
{
    // �º��� ���ڿ��� ���̰� ���� ������ 1 �� ����
    // �캯�� ���ڿ��� ���� ������ �����̸� 1 �� ����
    // �� �� 1�� ������ ���, AND �������� 1�� �����ؼ� true
    return (a.length() == b.length() && a < b);
}

int main()
{
    int n;
    cin >> n;

    vector<string> str(n);

    for (int i = 0; i < n; i++)
        cin >> str[i];
    // ���̿� ���� �������� ����
    sort(str.begin(), str.end(), desc);

    // ���̰� ���� ���ڿ����� ������ ����
    // ������ sort �� �ϸ� �ݷ� �߻����� Ʋ�� > stable_sort �� �����ؼ� ����
    stable_sort(str.begin(), str.end(), compare_lib);

    for (int i = 0; i < str.size(); i++)
    {
        // �ߺ� ���ڿ� ó��
        if (i != 0 && str[i - 1] == str[i])
            continue;
        cout << str[i] << endl;
    }
}