#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ������������ �����ϴ� �Լ�
void SortCoord(vector<vector<int>> &vec)
{
    sort(vec.begin(), vec.end());
}

int main()
{
    int N;
    cin >> N;

    // N ���� �࿡�� 2���� ���� ���� 2���� ���� ����
    vector<vector<int>> coord(N, vector<int>(2));

    for (int i = 0; i < N; i++)
    {
        // �Է��� �������� �ް�
        cin >> coord[i][1] >> coord[i][0];
    }
    // �������� ������ �� ��
    SortCoord(coord);
    // �ٽ� ��� ���� �����Ѵ�.
    for (int i = 0; i < coord.size(); i++)
        swap(coord[i][0], coord[i][1]);

    for (int i = 0; i < N; i++)
    {
        // endl �� ��� ���� ��, endl�� �ſ� ���ſ� �����̹Ƿ� �ð��ʰ��� �߻��Ѵ�.
        // ���� endl ��� ���� ���ڸ� ����Ͽ� ���� �ӵ��� �ø���.
        cout << coord[i][0] << " " << coord[i][1] << "\n";
    }
    coord.clear();
}