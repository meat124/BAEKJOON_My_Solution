#include <iostream>
#include <string>
#include <list>

class queue
{
    std::list<int> lst;

public:
    queue() : lst() {}

    void Push(int n)
    {
        lst.push_back(n);
    }
    int Pop()
    {
        if (lst.empty())
            return -1;
        int temp = lst.front();
        lst.pop_front();
        return temp;
    }
    int size()
    {
        return lst.size();
    }
    int Empty()
    {
        return lst.empty();
    }
    int Front()
    {
        if (lst.empty())
            return -1;
        return lst.front();
    }
    int Back()
    {
        if (lst.empty())
            return -1;
        return lst.back();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;
    std::cin.ignore();
    queue q;
    std::string str;
    std::string str_piece;
    for (int i = 0; i < N; i++)
    {
        std::getline(std::cin, str);
        str_piece = str.substr(0, 3);
        if (str_piece == "pus")
            q.Push(stoi(str.substr(5)));
        else if (str_piece == "pop")
            std::cout << q.Pop() << "\n";
        else if (str_piece == "siz")
            std::cout << q.size() << "\n";
        else if (str_piece == "emp")
            std::cout << q.Empty() << "\n";
        else if (str_piece == "fro")
            std::cout << q.Front() << "\n";
        else if (str_piece == "bac")
            std::cout << q.Back() << "\n";
    }
}