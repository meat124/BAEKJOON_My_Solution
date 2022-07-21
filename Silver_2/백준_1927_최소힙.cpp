#include<iostream>
#include<map>
using namespace std;
int N;
unsigned int min_value = (1 << 31);
map<int , int> arr;
// vector �� ����ϸ� �ð����⵵ �ʰ�(front ���� �� �ϴ� ���)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for (int i = 0;i < N;i++)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            if (arr.empty())
                cout << 0 << "\n";
            else
            {
                min_value = arr.begin()->first;
                cout << min_value << "\n";
                if (arr[min_value] == 1)
                    arr.erase(min_value);
                else
                    arr[min_value]--;
            }
        }
        else
        {
            if (arr.find(x) == arr.end())
                arr.insert({ x,1 });
            else
                arr[x]++;
        }
    }
}