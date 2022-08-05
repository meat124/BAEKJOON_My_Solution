#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int N;
vector<int> coord(1000005);
vector<int> sorted_coord;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        cin >> coord[i];
        sorted_coord.push_back(coord[i]);
    }
    // unique 멤버 함수는 중복을 제거하고 뒤를 쓰레기 값으로 초기화 한다.
    // 그리고 쓰레기 값이 시작하는 지점의 iterator 를 반환한다.
    // unique 함수는 컨테이너가 정렬되어 있어야 정상적으로 작동한다.
    sort(sorted_coord.begin() , sorted_coord.end());
    sorted_coord.erase(unique(sorted_coord.begin() , sorted_coord.end()) , sorted_coord.end());
    for (int i = 0;i < N;i++)
        cout << lower_bound(sorted_coord.begin() , sorted_coord.end() , coord[i]) - sorted_coord.begin() << " ";
}