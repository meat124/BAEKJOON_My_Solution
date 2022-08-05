#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N , M;
vector<int> numbers;

int Binary_Search(int n)
{
    // 인덱스를 가리킴
    int start = 0 , end = numbers.size() - 1;
    int center;
    while (start <= end)
    {
        center = (start + end) / 2;
        // center 인덱스의 값이 n 보다 작다면
        if (numbers[center] < n)
            start = center + 1;
        else if (numbers[center] > n)
            end = center - 1;
        else
            return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        int n;
        cin >> n;
        numbers.push_back(n);
    }
    sort(numbers.begin() , numbers.end());

    cin >> M;
    while (M--)
    {
        int n;
        cin >> n;
        cout << Binary_Search(n) << "\n";
    }
    return 0;
}