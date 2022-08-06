#include<iostream>
using namespace std;
int N , S;
int seq[100005];
int min_length = 0x7FFFFFFF;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    for (int i = 0;i < N;i++)
        cin >> seq[i];
    int end = 0;
    int cur_sum = seq[0];
    for (int start = 0;start < N;start++)
    {
        while (end < N && cur_sum < S)
        {
            end++;
            cur_sum += seq[end];
        }
        if (end == N)
            break;
        min_length = min(min_length , end - start + 1);
        cur_sum -= seq[start];
    }
    if (min_length == 0x7FFFFFFF)
        cout << 0;
    else
        cout << min_length;
}