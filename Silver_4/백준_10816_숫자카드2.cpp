#include <iostream>
#include <unordered_map>

// �ؽø� �̿��ؼ� Ǯ������ ����� ���۸� ���� �ڵ带 �ۼ����� ������ �ð��ʰ�
// �����δ� �ؽú��� �̺� Ž���� �̿��Ͽ� Ǫ�� ���� �� ������.
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;
    std::unordered_map<int, int> m_map;

    for (int i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        m_map[n]++;
    }

    int M;
    std::cin >> M;

    for (int i = 0; i < M; i++)
    {
        int n;
        std::cin >> n;
        std::cout << m_map[n] << " ";
    }
}