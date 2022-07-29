#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N , M;
vector<int> D;
bool disability_num[10];

// 인자로 받은 숫자에 사용 불가능한 번호가 있다면 false, 없다면 true 를 리턴하는 함수
bool Check(int cur)
{
    string s_cur = to_string(cur); // 현재 탐색하고 있는 번호를 string 으로 캐스팅

    for (int i = 0;i < s_cur.length();i++)
        if (disability_num[s_cur[i] - '0']) // 번호에 고장난 번호가 들어가 있다면
            return false; // false 를 리턴한다.
    return true; // 고장난 번호가 없다면 true 를 리턴한다.
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    int tmp;
    for (int i = 0;i < M;i++)
    {
        cin >> tmp;
        disability_num[tmp] = true; // 사용 불가한 번호 true 로 초기화
    }

    string str_N = to_string(N);

    int min_cnt = abs(N - 100); // 100에서 이동하는 횟수를 시작값으로 설정

    // 0 부터 10^6까지 모든 수를 전부 경우를 계산하여 최소 이동 횟수를 탐색한다.
    for (int i = 0;i <= 1000000;i++)
    {
        if (Check(i)) // 만약 고장난 번호가 없다면 최소값을 계산한다.
        {
            // N 까지의 1씩 이동 횟수 + 현재 i 를 입력하는데 필요한 횟수
            tmp = abs(N - i) + to_string(i).length();
            min_cnt = min(min_cnt , tmp);
        }
        // i 에 고장난 번호가 있다면 그 번호는 카운트 할 필요가 없다.
    }

    cout << min_cnt;
}