#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 오름차순으로 정렬하는 함수
void SortCoord(vector<vector<int>> &vec)
{
    sort(vec.begin(), vec.end());
}

int main()
{
    int N;
    cin >> N;

    // N 개의 행에서 2개의 열을 가진 2차원 벡터 선언
    vector<vector<int>> coord(N, vector<int>(2));

    for (int i = 0; i < N; i++)
    {
        // 입력을 역순으로 받고
        cin >> coord[i][1] >> coord[i][0];
    }
    // 오름차순 정렬을 한 뒤
    SortCoord(coord);
    // 다시 행과 열을 스왑한다.
    for (int i = 0; i < coord.size(); i++)
        swap(coord[i][0], coord[i][1]);

    for (int i = 0; i < N; i++)
    {
        // endl 로 출력 종료 시, endl은 매우 무거운 연산이므로 시간초과가 발생한다.
        // 따라서 endl 대신 개행 문자를 사용하여 연산 속도를 늘린다.
        cout << coord[i][0] << " " << coord[i][1] << "\n";
    }
    coord.clear();
}