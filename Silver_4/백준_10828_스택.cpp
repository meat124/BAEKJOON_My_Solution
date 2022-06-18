#include <iostream>
#include <string>
#include <vector>

class Stk
{
    std::vector<int> vec;

public:
    // Ǫ��
    void Push(int n)
    {
        vec.push_back(n);
    }

    // ��
    int Pop()
    {
        if (vec.empty())
            return -1;
        int n = vec[vec.end() - vec.begin() - 1];
        vec.pop_back();
        return n;
    }

    // ������
    int Size()
    {
        return vec.size();
    }

    // ��������� 1, �ƴϸ� 0
    int Empty()
    {
        if (vec.empty())
            return 1;
        else
            return 0;
    }

    // ��ũ
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
            stk.Push(stoi(s.substr(5))); // �� ���ڸ� ������ �ƴҼ��� �����Ƿ� Ǫ�úκп� ������ �߶� ���ڷ� ����
        else if (s == "size")
            std::cout << stk.Size() << "\n";
        else if (s == "empty")
            std::cout << stk.Empty() << "\n";
    }
}