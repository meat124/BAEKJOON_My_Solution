#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N , S;
int seq[42];
map<int , int> subsum; // 부분합이 음수인 경우도 포함하려면 배열이 아니라 맵이 필요하다.
ll result;

void Right_Seq(int mid , int sum)
{
    if (mid == N)
    {
        subsum[sum]++;
        return;
    }
    // 재귀함수로 부분합 계산
    Right_Seq(mid + 1 , sum + seq[mid]); // 합하고 다음
    Right_Seq(mid + 1 , sum); // 건너뛰기
}

void Left_Seq(int st , int sum)
{
    if (st == N / 2)
    {
        result += subsum[S - sum];
        return;
    }
    // 재귀함수로 부분합 계산
    Left_Seq(st + 1 , sum + seq[st]); // 합하고 다음
    Left_Seq(st + 1 , sum); // 건너뛰기
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    for (int i = 0;i < N;i++)
        cin >> seq[i];
    // N이 최대 40이므로 그냥 모든 부분합을 구하려면 >> 2^40 의 시간복잡도 >> TLE
    // 따라서 수열을 반으로 나눈다. >> 20 크기의 수열 2개 >> 2^20 * 2 의 시간복잡도
    // map 자료구조를 통해서 부분합이 등장한 개수를 센다.
    Right_Seq(N / 2 , 0);
    Left_Seq(0 , 0);
    // 만약 S == 0 이면
    if (!S)
        cout << result - 1;
    else
        cout << result;
}