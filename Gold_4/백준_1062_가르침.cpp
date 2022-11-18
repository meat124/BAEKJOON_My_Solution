#include<bits/stdc++.h>
using namespace std;
int N , K , result;
vector<int> V;
vector<string> words;
char back_front[5] = { 'a', 'c', 't', 'i', 'n' };

bool Can_Read(const string& str)
{
    for (auto i : str)
        if (!V[i - 'a'])
            return false;
    return true;
}

bool Can_Read_Back_Front()
{
    for (int i = 0;i < 5;i++)
        if (!V[back_front[i] - 'a'])
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 0;i < 26 - K;i++)
        V.push_back(0);
    for (int i = 0;i < K;i++)
        V.push_back(1);
    for (int i = 0;i < N;i++)
    {
        string str;
        cin >> str;
        words.push_back(str.substr(4 , str.size() - 8));
    }
    do
    {
        if (!Can_Read_Back_Front())
            continue;
        int cur = 0;
        for (auto s : words)
            if (Can_Read(s))
                cur++;
        result = max(result , cur);
    } while (next_permutation(V.begin() , V.end()));
    cout << result;
}