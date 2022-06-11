#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Self_Number(int n, vector<int> &vec)
{
    // n 부터 시작해서 계속해서 수열을 만들면서 그 수들을 벡터에서 제외한다.
    // 벡터에서 제외한다는 의미는 그 값과 같은 인덱스의 값을 1로 초기화 시키는 것이다.

    int d_n = n;
    string str_n = to_string(n);
    for (int i = 0; i < str_n.size(); i++)
    {
        d_n += (str_n[i] - 48);
    }
    if (d_n <= 10000)
    {
        vec[d_n] = 1;
        Self_Number(d_n, vec);
    }
    else
        return;
}

int main()
{
    vector<int> int_vec(10001); // int 타입 벡터 생성 후 모든 요소를 0으로 초기화

    for (int i = 1; i <= 10000; i++)
    {
        if (int_vec[i] == 1)
            continue;
        Self_Number(i, int_vec);
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (int_vec[i] == 0)
            cout << i << endl;
    }
}