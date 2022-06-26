#include <iostream>
#include <map>
#include <string>

int main()
{
    int N;
    std::cin >> N;

    std::string str;
    std::map<std::string, int> book_title;
    std::map<std::string, int>::iterator itr;
    for (size_t i = 0; i < N; i++)
    {
        std::cin >> str;
        itr = book_title.find(str);
        if (itr == book_title.end())
            book_title.insert(std::pair<std::string, int>(str, 1));
        else
            itr->second++;
    }
    std::string steady_title = book_title.begin()->first;
    for (itr = book_title.begin(); itr != book_title.end(); ++itr)
    {
        if (book_title.find(steady_title)->second < itr->second)
            steady_title = itr->first;
    }
    std::cout << steady_title;
}