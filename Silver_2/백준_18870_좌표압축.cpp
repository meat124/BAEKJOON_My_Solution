#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int N;
vector<int> coord(1000005);
vector<int> sorted_coord;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        cin >> coord[i];
        sorted_coord.push_back(coord[i]);
    }
    // unique ��� �Լ��� �ߺ��� �����ϰ� �ڸ� ������ ������ �ʱ�ȭ �Ѵ�.
    // �׸��� ������ ���� �����ϴ� ������ iterator �� ��ȯ�Ѵ�.
    // unique �Լ��� �����̳ʰ� ���ĵǾ� �־�� ���������� �۵��Ѵ�.
    sort(sorted_coord.begin() , sorted_coord.end());
    sorted_coord.erase(unique(sorted_coord.begin() , sorted_coord.end()) , sorted_coord.end());
    for (int i = 0;i < N;i++)
        cout << lower_bound(sorted_coord.begin() , sorted_coord.end() , coord[i]) - sorted_coord.begin() << " ";
}