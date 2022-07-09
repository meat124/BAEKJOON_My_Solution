#include <iostream>

using namespace std;

void Hanoi(int n, int start, int end) // N ��° ������ start > end �� �ű��.
{
    if (n == 1)
    {
        cout << start << " " << end << "\n";
        return;
    }
    // n - 1 ���� ������ start ���� 6 - start - end �� �ű��.
    Hanoi(n - 1, start, 6 - start - end);
    // n ��° ������ start ���� end �� �ű��.
    cout << start << " " << end << "\n";
    // n - 1 ���� ������ 6 - start - end ���� end �� �ű��.
    Hanoi(n - 1, 6 - start - end, end);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    // math.h ���̺귯���� pow �Լ��� �̿��Ͽ� 2^N - 1 �� ����ϸ� N = 20 �� �� ���� �߻�(double)
    cout << (1 << N) - 1 << "\n";
    Hanoi(N, 1, 3);
}