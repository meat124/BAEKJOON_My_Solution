#include<bits/stdc++.h>
using namespace std;
int N;
int result_value = 0x7FFFFFFF;
pair<int , int> result_sol;
vector<int> solution;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        int n;
        cin >> n;
        solution.push_back(n);
    }
    int st = 0 , en = N - 1;
    while (st < en)
    {
        int value = abs(solution[st] + solution[en]);
        if (value < result_value)
        {
            result_value = value;
            result_sol = { st,en };
        }
        if (solution[st] + solution[en] < 0)
            st++;
        else if (solution[st] + solution[en] > 0)
            en--;
        else
            break;
    }
    cout << solution[result_sol.first] << " " << solution[result_sol.second];
}