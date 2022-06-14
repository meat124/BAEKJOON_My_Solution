#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int factorial = 1;
    int zero = 0;

    for (int i = 2; i <= N; i++)
    {
        factorial *= i;
        while (factorial % 10 == 0)
        {
            factorial /= 10;
            zero += 1;
        }
        if (to_string(factorial).size() > 4)
        {
            factorial = stoi(to_string(factorial).substr(to_string(factorial).size() - 3));
        }
    }
    cout << zero;
}