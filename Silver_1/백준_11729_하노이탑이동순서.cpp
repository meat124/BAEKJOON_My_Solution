#include <iostream>

using namespace std;

void Hanoi(int n, int start, int end) // N 번째 원반을 start > end 로 옮긴다.
{
    if (n == 1)
    {
        cout << start << " " << end << "\n";
        return;
    }
    // n - 1 개의 원판을 start 에서 6 - start - end 로 옮긴다.
    Hanoi(n - 1, start, 6 - start - end);
    // n 번째 원판을 start 에서 end 로 옮긴다.
    cout << start << " " << end << "\n";
    // n - 1 개의 원판을 6 - start - end 에서 end 로 옮긴다.
    Hanoi(n - 1, 6 - start - end, end);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    // math.h 라이브러리의 pow 함수를 이용하여 2^N - 1 을 계산하면 N = 20 일 때 오차 발생(double)
    cout << (1 << N) - 1 << "\n";
    Hanoi(N, 1, 3);
}