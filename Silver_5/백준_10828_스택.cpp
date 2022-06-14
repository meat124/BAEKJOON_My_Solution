#include <iostream>
#include <string>
#include <vector>

class Stk
{
    std::vector<int> vec;

public:
    // 푸시
    void Push(int n)
    {
        vec.push_back(n);
    }

    // 팝
    int Pop()
    {
        if (vec.empty())
            return -1;
        int n = vec[vec.end() - vec.begin() - 1];
        vec.pop_back();
        return n;
    }

    // 사이즈
    int Size()
    {
        return vec.size();
    }

    // 비어있으면 1, 아니면 0
    int Empty()
    {
        if (vec.empty())
            return 1;
        else
            return 0;
    }

    // 피크
    int Top()
    {
        if (vec.empty())
            return -1;
        return vec[vec.end() - vec.begin() - 1];
    }
};

int main()
{
    int N;
    std::cin >> N;
    Stk stk;

    for (int i = 0; i < N + 1; i++)
    {
        std::string s;
        std::getline(std::cin, s);
        if (s == "pop")
            std::cout << stk.Pop() << "\n";
        else if (s == "top")
            std::cout << stk.Top() << "\n";
        else if (s.substr(0, 4) == "push")
            stk.Push(stoi(s.substr(5))); // 꼭 한자리 정수가 아닐수도 있으므로 푸시부분에 정수를 잘라서 인자로 전달
        else if (s == "size")
            std::cout << stk.Size() << "\n";
        else if (s == "empty")
            std::cout << stk.Empty() << "\n";
    }
}