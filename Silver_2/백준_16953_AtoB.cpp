#include<bits/stdc++.h>
using namespace std;
int A , B;

void Cal(int cur , int cnt)
{
    if (cur == A)
    {
        cout << cnt;
        return;
    }
    if (cur < A)
    {
        cout << -1;
        return;
    }
    string cur_s = to_string(cur);
    if (cur_s.back() == '1')
    {
        cur_s.pop_back();
        Cal(stoi(cur_s) , cnt + 1);
    }
    else if (cur % 2 == 0)
        Cal(cur / 2 , cnt + 1);
    else
    {
        cout << -1;
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A >> B;
    Cal(B , 1);
}