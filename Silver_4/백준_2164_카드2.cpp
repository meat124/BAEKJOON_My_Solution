#include <iostream>
#include <queue>

int main()
{
    int N;
    std::cin >> N;

    std::queue<int> q; // 큐를 선언한다.

    for (int i = 0; i < N; i++)
        q.push(i + 1); // 시간 복잡도 O(n)
    int temp;
    while (q.size() != 1) // 시간 복잡도 O(n)
    {
        q.pop(); // 시간 복잡도 O(1)
        if (q.size() == 1)
            break;
        temp = q.front();
        q.pop();
        q.push(temp);
    }
    std::cout << q.front();
}