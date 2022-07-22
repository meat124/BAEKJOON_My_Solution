#include<iostream>
#include<list>
#include<string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string init;
    list<char> str;
    cin >> init;
    for (auto c : init)
        str.push_back(c);
    auto cursor = str.end();
    int M;
    cin >> M;
    for (int i = 0;i < M;i++)
    {
        char input;
        cin >> input;
        if (input == 'P')
        {
            char add;
            cin >> add;
            str.insert(cursor , add);
        }
        else if (input == 'L' && cursor != str.begin())
            cursor--;
        else if (input == 'D' && cursor != str.end())
            cursor++;
        else if (input == 'B' && cursor != str.begin())
        {
            cursor--;
            cursor = str.erase(cursor);
        }
    }
    for (auto c : str)
        cout << c;
}