#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ������������ �����ϴ� �Լ�
void CheckXCoord(vector<vector<int>> &vec)
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
        cin >> coord[i][0] >> coord[i][1];
    }

    CheckXCoord(coord);

    for (int i = 0; i < N; i++)
    {
        // endl �� ��� ���� ��, endl�� �ſ� ���ſ� �����̹Ƿ� �ð��ʰ��� �߻��Ѵ�.
        // ���� endl ��� ���� ���ڸ� ����Ͽ� ���� �ӵ��� �ø���.
        cout << coord[i][0] << " " << coord[i][1] << "\n";
    }
    coord.clear();
}