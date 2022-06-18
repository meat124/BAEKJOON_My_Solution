#include <iostream>
#include <string>
#include <vector>

class Deque
{
    std::vector<int> v;

public:
    void Push_Front(int n)
    {
        v.insert(v.begin(), n);
    }
    void Push_Back(int n)
    {
        v.push_back(n);
    }
    int Pop_Front()
    {
        if (v.begin() == v.end())
            return -1;
        int temp = *v.begin();
        v.erase(v.begin());
        return temp;
    }
    int Pop_Back()
    {
        if (v.begin() == v.end())
            return -1;
        int temp = *(v.end() - 1);
        v.pop_back();
        return temp;
    }
    int Size()
    {
        return v.size();
    }
    int Empty()
    {
        if (v.begin() == v.end())
            return 1;
        return 0;
    }
    int Front()
    {
        if (v.begin() == v.end())
            return -1;
        return *v.begin();
    }
    int Back()
    {
        if (v.begin() == v.end())
            return -1;
        return *(v.end() - 1);
    }
};

int main()
{
    int N;
    std::cin >> N;
    std::cin.ignore();
    Deque deq;
    for (int i = 0; i < N; i++)
    {
        std::string order;
        std::getline(std::cin, order);

        if (order.substr(0, 6) == "push_f")
        {
            deq.Push_Front(stoi(order.substr(11))); // 입력을 원하는 숫자는 인덱스 11에 위치
        }
        else if (order.substr(0, 6) == "push_b")
        {
            deq.Push_Back(stoi(order.substr(10)));
        }
        else if (order.substr(0, 5) == "pop_f")
        {
            std::cout << deq.Pop_Front() << "\n";
        }
        else if (order.substr(0, 5) == "pop_b")
        {
            std::cout << deq.Pop_Back() << "\n";
        }
        else if (order == "size")
        {
            std::cout << deq.Size() << "\n";
        }
        else if (order == "empty")
        {
            std::cout << deq.Empty() << "\n";
        }
        else if (order == "front")
        {
            std::cout << deq.Front() << "\n";
        }
        else if (order == "back")
        {
            std::cout << deq.Back() << "\n";
        }
    }
}