#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �ð� ���⵵�� log N > Big O ǥ���
int BinarySearch(vector<int> &v, int val)
{
    int begin = 0, end = v.end() - v.begin();

    while (begin <= end)
    {
        int ctr = (begin + end) / 2;

        if (v[ctr] == val)
            return 1;
        else if (v[ctr] < val)
        {
            begin = ctr + 1;
        }
        else // v[ctr] > val �� ���
        {
            end = ctr - 1;
        }
    }
    return 0;
}

int main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    int num;

    cin >> N;
    vector<int> vec1;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        vec1.push_back(num);
    }
    // ���� Ž���� ���� �������� ����
    sort(vec1.begin(), vec1.end());
    cin >> M;
    vector<int> vec2, vec3;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        vec2.push_back(num);

        // find �Լ��� 3��° ���ڸ� vec2.begin() ���� �ϸ� const Ÿ���� �ƴϹǷ� ������ ������ �߻��Ѵ�.
        if (BinarySearch(vec1, vec2[0])) // vec1.end() �� ��ȯ�Ǹ� �ش� ���Ұ� �������� �ʴ� ��
            vec3.push_back(1);
        else
            vec3.push_back(0);
        vec2.erase(vec2.begin());
    }

    for (int i = 0; i < M; i++)
        cout << vec3[i] << " ";
}