#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int L , C;
vector<char> alpha;
vector<char> password;
char arr[5] = { 'a', 'e', 'i', 'o', 'u' };

void Print()
{
    for (auto itr : password)
        cout << itr;
    cout << "\n";
}

// password 에 자음이 2개, 모음이 1개 이상 존재하는지 확인하는 함수
bool Is_right()
{
    int cnt = 0;
    for (auto itr : password)
        for (int i = 0;i < 5;i++)
            if (itr == arr[i])
                cnt++;
    if (cnt > 0 && L - cnt > 1)
        return true;
    return false;
}

void DFS(int level , int cur)
{
    if (level == L)
    {
        if (Is_right())
            Print();
        return;
    }
    for (int i = cur + 1;i < C;i++)
    {
        password.push_back(alpha[i]);
        DFS(level + 1 , i);
        password.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> L >> C;
    for (int i = 0;i < C;i++)
    {
        char c;
        cin >> c;
        alpha.push_back(c);
    }
    sort(alpha.begin() , alpha.end());
    for (int i = 0;i < C - L + 1;i++)
    {
        password.push_back(alpha[i]);
        DFS(1 , i);
        password.pop_back();
    }
}