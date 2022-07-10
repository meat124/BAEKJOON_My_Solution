#include <iostream>
using namespace std;
;

int arr[12]; // arr[i] 는 i 를 1,2,3의 합으로 나타내기 위한 경우의 수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    // 미리 구해두는 것이 효율적
    for (size_t i = 4; i <= 11; i++)
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << arr[N] << "\n";
    }
}