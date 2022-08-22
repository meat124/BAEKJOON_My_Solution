#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
int N , M , K;
char board[15][15];
// BFS 를 8방향으로 시행한다.
int dx[8] = { 1,0,-1,0, 1,1, -1 ,-1 };
int dy[8] = { 0,1,0,-1, 1,-1, 1, -1 };
vector<string> god_liked;
unordered_map<string , int> cases;

void Change_Coord(int& nx , int& ny)
{
    if (nx < 1) nx = N;
    else if (nx > N) nx = 1;
    if (ny < 1) ny = M;
    else if (ny > M) ny = 1;
}

void DFS(string& result , string cur , int x , int y)
{
    if (result.length() == cur.length())
    {
        if (result == cur)
            cases[result]++;
        return;
    }
    for (int i = 0;i < 8;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        Change_Coord(nx , ny);
        cur += board[nx][ny];
        DFS(result , cur , nx , ny);
        cur.pop_back();
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= M;j++)
            cin >> board[i][j];
    while (K--)
    {
        string s;
        cin >> s;
        god_liked.push_back(s);
    }
    // time complexity = 1000*10*10*8^5
    for (string s : god_liked)
    {
        // 좋아하는 문자열이 중복이라면 해시에 저장된 값을 출력한다.
        if (cases.find(s) != cases.end())
        {
            cout << cases[s] << "\n";
            continue;
        }
        cases[s] = 0;
        for (int i = 1;i <= N;i++)
            for (int j = 1;j <= M;j++)
                if (board[i][j] == s[0])
                {
                    string str(1 , board[i][j]);
                    DFS(s , str , i , j);
                }
        cout << cases[s] << "\n";
    }
}