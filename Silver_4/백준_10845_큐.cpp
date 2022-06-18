#include <iostream>
#include <string>
#include <vector>

class Queue
{
    std::vector<int> queue;

public:
    void Push(int n)
    {
        queue.push_back(n);
    }
    int Pop()
    {
        if (queue.begin() == queue.end())
            return -1;
        int n = *queue.begin();
        queue.erase(queue.begin());
        return n;
    }
    int Size()
    {
        return queue.size();
    }
    int Empty()
    {
        return queue.begin() == queue.end();
    }
    int Front()
    {
        if (queue.begin() == queue.end())
            return -1;
        else
            return queue.front();
    }
    int Back()
    {
        if (queue.begin() == queue.end())
            return -1;
        else
            return queue.back();
    }
};

int main()
{
    int N;
    std::cin >> N;
    Queue q;
    std::cin.ignore();
    for (int i = 0; i < N; i++)
    {
        std::string order;
        std::getline(std::cin, order);
        if (order == "empty")
            std::cout << q.Empty() << "\n";
        else if (order == "front")
            std::cout << q.Front() << "\n";
        else if (order == "back")
            std::cout << q.Back() << "\n";
        else if (order == "size")
            std::cout << q.Size() << "\n";
        else if (order == "pop")
            std::cout << q.Pop() << "\n";
        else
        {
            q.Push(stoi(order.substr(5)));
        }
    }
    return 0;
}