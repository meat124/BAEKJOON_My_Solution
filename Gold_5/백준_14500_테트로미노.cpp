#include<iostream>
#include<vector>
using namespace std;
int N , M;
int board[501][501];
vector<vector<pair<int , int>>> tetro(19);
int max_result = 0;

void Find_max_sum(vector<pair<int , int>> t)
{

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            bool flag = false;
            int cur_sum = 0;
            vector<pair<int , int>> tmp = t;
            for (int k = 0;k < 4;k++)
            {
                tmp[k].first += i;
                tmp[k].second += j;
                if (tmp[k].first >= N || tmp[k].second >= M)
                {
                    flag = true;
                    break;
                }
                cur_sum += board[tmp[k].first][tmp[k].second];
            }
            if (flag)
                break;
            max_result = max_result > cur_sum ? max_result : cur_sum;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            cin >> board[i][j];
    // 1번
    tetro[0] = { {0,0}, {0,1}, {0,2}, {0,3} };
    tetro[1] = { {0,0}, {1,0}, {2,0}, {3,0} };
    // 2번
    tetro[2] = { {0,0}, {0,1}, {1,0}, {1,1} };
    // 3번
    tetro[3] = { {0,0}, {1,0}, {2,0}, {2,1} };
    tetro[4] = { {0,0}, {0,1}, {0,2}, {1,0} };
    tetro[5] = { {0,0}, {0,1}, {1,1}, {2,1} };
    tetro[6] = { {0,2}, {1,0}, {1,1}, {1,2} };
    // 3번 대칭
    tetro[7] = { {0,1}, {1,1}, {2,0}, {2,1} };
    tetro[8] = { {0,0}, {1,0}, {1,1}, {1,2} };
    tetro[9] = { {0,0}, {0,1}, {1,0}, {2,0} };
    tetro[10] = { {0,0}, {0,1}, {0,2}, {1,2} };
    // 4번
    tetro[11] = { {0,0}, {1,0}, {1,1}, {2,1} };
    tetro[12] = { {0,1}, {0,2}, {1,0}, {1,1} };
    // 4번 대칭
    tetro[13] = { {0,1}, {1,0}, {1,1}, {2,0} };
    tetro[14] = { {0,0}, {0,1}, {1,1}, {1,2} };
    // 5번
    tetro[15] = { {0,0}, {0,1}, {0,2}, {1,1} };
    tetro[16] = { {0,1}, {1,0}, {1,1}, {2,1} };
    tetro[17] = { {0,1}, {1,0}, {1,1}, {1,2} };
    tetro[18] = { {0,0}, {1,0}, {1,1}, {2,0} };

    for (int i = 0;i < 19;i++)
        Find_max_sum(tetro[i]);
    cout << max_result;
}