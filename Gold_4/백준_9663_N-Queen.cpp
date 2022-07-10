#include <iostream>
using namespace std;

int N;
bool visit1[40]; // 각 열에 퀸이 있는지를 확인하는 배열
bool visit2[40]; // 우상향 대각선에 퀸이 있는지를 확인하는 배열
bool visit3[40]; // 우하향 대각선에 퀸이 있는지를 확인하는 배열
int result = 0;  // 퀸을 서로 공격하지 못하게 놓는 경우의 수

// k 번째 행에 배치를 시작한다.
void Queen(int k)
{
    if (k == N)
    {
        result++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (visit1[i] || visit2[i + k] || visit3[k - i + N - 1])
            continue;
        visit1[i] = true;
        visit2[i + k] = true;
        visit3[k - i + N - 1] = true;
        Queen(k + 1);
        visit1[i] = false;
        visit2[i + k] = false;
        visit3[k - i + N - 1] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    Queen(0);
    cout << result;
}