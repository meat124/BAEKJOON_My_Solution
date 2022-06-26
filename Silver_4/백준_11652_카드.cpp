#include <iostream>
#include <string>
#include <map>

// ������ key ���� string ���� �޾Ҵ��� string ���� ũ�� �񱳸� �ϴµ� �����
// ���� string �� �ƴ� long long Ÿ������ key �� �޾Ƽ� �ذ�
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;

    std::map<long long, int> m_map; // key �� ����ī�忡 ���� ������ �Էµǰ�, value �� �� ������ �Էµȴ�.
    long long lld;
    for (size_t i = 0; i < N; i++)
    {
        std::cin >> lld;
        // �Է¹��� str �� m_map �� �����ϴ��� Ȯ���Ѵ�.
        std::map<long long, int>::iterator itr = m_map.find(lld);
        // ���� str �� m_map �� �������� ������ itr == m_map.end() �̴�.
        if (itr != m_map.end())
            itr->second++;
        else
            m_map.insert(std::pair<long long, int>(lld, 1)); // �������� �ʴ´ٸ� ���Ӱ� pair �߰��ϰ� value = 1�� ����
    }
    // ���� ���� ������ �ִ� ������ ���� �� ��� �� �� key �� ���� ���� ��� �ؾ��Ѵ�.
    int max = 0; // value �� ��
    long long result = 0;
    for (auto itr = m_map.begin(); itr != m_map.end(); ++itr)
    {
        if (max < itr->second)
        {
            max = itr->second;
            result = itr->first;
        }
    }
    std::cout << result;
}