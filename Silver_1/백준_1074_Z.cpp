#include <iostream>
using namespace std;

int r, c;

// 2^N * 2^N ¥�� �迭���� (r ,c) �� ��� ��и鿡 �����ϴ��� Ž���Ѵ�.
int Z(int N, pair<int, int> start, pair<int, int> end)
{
    if (N == 0)
        return 0;
    // �߽� ����
    pair<int, int> ctr = {(start.first + end.first) / 2, (start.second + end.second) / 2};
    int quarter_area = (1 << (N - 1)) * (1 << (N - 1));
    // 2 ��и鿡 ����
    if (ctr.first >= r && ctr.second >= c)
    {
        // �湮 ������ ������Ű�� �ʴ´�.
        return Z(N - 1, start, ctr);
    }
    // 1 ��и鿡 ����
    else if (ctr.first >= r && ctr.second < c)
    {
        return quarter_area + Z(N - 1, {start.first, ctr.second + 1}, {ctr.first, end.second});
    }
    // 3 ��и鿡 ����
    else if (ctr.first < r && ctr.second >= c)
    {
        return quarter_area * 2 + Z(N - 1, {ctr.first + 1, start.second}, {end.first, ctr.second});
    }
    // 4 ��и鿡 ����
    else if (ctr.first < r && ctr.second < c)
    {
        return quarter_area * 3 + Z(N - 1, {ctr.first + 1, ctr.second + 1}, end);
    }
}

int main()
{
    int N;
    cin >> N >> r >> c;

    cout << Z(N, {0, 0}, {(1 << N) - 1, (1 << N) - 1});
}