#include <iostream>
using namespace std;

int N;
bool visit1[40]; // �� ���� ���� �ִ����� Ȯ���ϴ� �迭
bool visit2[40]; // ����� �밢���� ���� �ִ����� Ȯ���ϴ� �迭
bool visit3[40]; // ������ �밢���� ���� �ִ����� Ȯ���ϴ� �迭
int result = 0;  // ���� ���� �������� ���ϰ� ���� ����� ��

// k ��° �࿡ ��ġ�� �����Ѵ�.
void Queen(int k)
{
    if (k == N)
    {
        result++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (visit1[i] || visit2[i + k] || visit3[k - i + N - 1])
            continue;
        visit1[i] = true;
        visit2[i + k] = true;
        visit3[k - i + N - 1] = true;
        Queen(k + 1);
        visit1[i] = false;
        visit2[i + k] = false;
        visit3[k - i + N - 1] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    Queen(0);
    cout << result;
}