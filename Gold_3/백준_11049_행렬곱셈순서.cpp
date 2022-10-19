#include<bits/stdc++.h>
using namespace std;
struct matrix
{
    int row , col;
    matrix(int row , int col) : row(row) , col(col) {}
    // 행렬의 곱 A*B 는 행은 A 를 따라가고, 열은 B 를 따라간다.
};
const int INF = 0x7FFFFFFF;
int N;
int DP[505][505]; // DP[i][j] 는 구간 [i,j] 에서의 최소 행렬 곱셈 횟수
vector<matrix> matrices;

int Multiplication(int n , int m , int k)
{
    return matrices[n].row * matrices[m].col * matrices[k].col;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        int r , c;
        cin >> r >> c;
        matrices.push_back(matrix(r , c));
    }
    for (int i = 1;i < N;i++) // i 는 구간 범위의 크기
        for (int j = 0;i + j < N;j++) // j 는 구간 범위의 시작점
        {
            DP[j][i + j] = INF;
            for (int k = j;k <= i + j;k++) // 구간 범위를 두 부분으로 나누는 기준점
                DP[j][i + j] = min(DP[j][i + j] ,
                    DP[j][k] + DP[k + 1][i + j] + Multiplication(j , k , i + j)); // [j,k] 까지 곱한 행렬과 [k + 1,i + j] 까지 곱한 행렬을 서로 곱한다.
        }
    cout << DP[0][N - 1];
}