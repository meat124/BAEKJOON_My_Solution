#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<string>> vec(N, vector<string>(2));

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i][0] >> vec[i][1];
    }

    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[j][0] == "0")
                continue;
            else if (i == stoi(vec[j][0]))
            {
                cout << vec[j][0] << " " << vec[j][1] << "\n";
                vec[j][0] = "0";
            }
        }
    }
}