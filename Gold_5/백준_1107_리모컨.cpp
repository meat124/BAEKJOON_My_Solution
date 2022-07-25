#include<iostream>
#include<vector>
#include<string>
using namespace std;
int N , M;
string N_str; // 원하는 채널 string 타입
int available_num[10]; // 고장난 번호는 1로 표시
string make_num;
int result = 50000000;

void Make_min_num()
{
    // 자릿수가 같아지면 result 와 값 비교하고 작은 값으로 초기화 한 후 종료
    if (make_num.length() == N_str.length())
    {
        int min_cnt = make_num.length() + abs(stoi(make_num) - N);
        result = result < min_cnt ? result : min_cnt;
        return;
    }
    for (int i = 0;i <= 9;i++)
    {
        // 만약 고장난 버튼이면 continue
        if (available_num[i] == 1)
            continue;
        make_num.push_back(i + 48);
        Make_min_num();
        make_num.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    N_str = to_string(N);
    cin >> M;
    for (int i = 0;i < M;i++)
    {
        int n;
        cin >> n;
        available_num[n] = 1;
    }
    // 가까운 수를 구한 뒤, 그 수와 N 의 차를 구한다.
    Make_min_num();
    vector<int> available;
    for (int i = 0;i < 10;i++)
    {
        if (available_num[i] == 0)
            available.push_back(i);
    }
    // 자릿수가 다른 수에서 최소값이 나오는 경우 예외 처리
    if (!available.empty())
    {
        int min_num = available.front();
        int max_num = available.back();
        string tmp_min , tmp_max;
        for (int i = 0;i < N_str.length() + 1;i++)
            tmp_min += (min_num + 48);
        for (int i = 0;i < N_str.length() - 1;i++)
            tmp_max += (max_num + 48);
        // stoi() std::invalid_argument error
        try {
            int tmp = tmp_min.length() + abs(stoi(tmp_min) - N);
            result = result < tmp ? result : tmp;
            tmp = tmp_max.length() + abs(stoi(tmp_max) - N);
            result = result < tmp ? result : tmp;
        }
        catch (std::exception) {
            cout << result;
            return 0;
        }
    }
    result = result < abs(N - 100) ? result : abs(N - 100);
    cout << result;
}