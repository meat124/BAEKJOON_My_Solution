#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;
int N;
unordered_set<string> company;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        string name , state;
        cin >> name >> state;
        if (state == "enter")
            company.insert(name);
        else
            company.erase(name);
    }
    vector<string> result(company.begin() , company.end());
    sort(result.begin() , result.end() , greater<string>());
    for (auto name : result)
        cout << name << "\n";
}