#include <iostream>
#include <queue>

int main()
{
    int N;
    std::cin >> N;

    std::queue<int> q; // ť�� �����Ѵ�.

    for (int i = 0; i < N; i++)
        q.push(i + 1); // �ð� ���⵵ O(n)
    int temp;
    while (q.size() != 1) // �ð� ���⵵ O(n)
    {
        q.pop(); // �ð� ���⵵ O(1)
        if (q.size() == 1)
            break;
        temp = q.front();
        q.pop();
        q.push(temp);
    }
    std::cout << q.front();
}