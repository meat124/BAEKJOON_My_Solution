#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000;
int N;
long long B;

void Print(const vector<vector<int>>& m)
{
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
            cout << m[i][j] << " ";
        cout << "\n";
    }
}

// 행렬곱셈 연산자 오버로딩
vector<vector<int>> operator*(vector<vector<int>>& a , vector<vector<int>>& b)
{
    vector<vector<int>> result(N , vector<int>(N));
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
        {
            for (int k = 0;k < N;k++)
                result[i][j] += a[i][k] * b[k][j];
            result[i][j] %= MOD;
        }
    return result;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> B;
    int tmp = N;
    vector<vector<int>> matrix(N , vector<int>(N)) , base(N , vector<int>(N));
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
            cin >> base[i][j];
        matrix[i][i] = 1;
    }

    while (B > 0)
    {
        if (B % 2 == 1)
            matrix = matrix * base;
        base = base * base;
        B /= 2;
    }
    Print(matrix);
}