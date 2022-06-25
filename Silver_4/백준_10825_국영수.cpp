#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 성적표 클래스
class Report_Card
{
    std::string name;
    int korean;
    int math;
    int a;

public:
    // 생성자
    Report_Card(std::string name, int korean, int math, int english)
        : name(name), korean(korean), math(math), a(english) {}
    void Print()
    {
        std::cout << name << "\n";
    }

    // private 변수 리턴
    std::string Return_Name()
    {
        return name;
    }
    int Return_Korean()
    {
        return korean;
    }
    int Return_Math()
    {
        return math;
    }
    int Return_English()
    {
        return a;
    }
};

int main()
{
    int N;
    std::cin >> N;
    std::string name;

    std::vector<Report_Card> RC;
    int k, m, e;
    for (int i = 0; i < N; i++)
    {
        std::cin >> name >> k >> e >> m;
        RC.push_back(Report_Card(name, k, m, e));
    }
    std::sort(RC.begin(), RC.end(), [](Report_Card RC1, Report_Card RC2)
              {
		if (RC1.Return_Korean() != RC2.Return_Korean())
			return RC1.Return_Korean() > RC2.Return_Korean();
		else if (RC1.Return_English() != RC2.Return_English())
			return RC1.Return_English() < RC2.Return_English();
		else if (RC1.Return_Math() != RC2.Return_Math())
			return RC1.Return_Math() > RC2.Return_Math();
		else if (RC1.Return_Name() != RC2.Return_Name())
			return RC1.Return_Name() < RC2.Return_Name();
		else
			return false; });

    for (auto itr = RC.begin(); itr != RC.end(); ++itr)
        itr->Print();
}