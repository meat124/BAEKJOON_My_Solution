#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N , M;
int T_people[60]; // 진실을 아는 사람은 true
int T_party[60]; // 진실을 말하는 파티는 true
vector<int> people_n[60]; // 파티 참석하는 사람 번호
vector<int> party_n[60]; // 참석하는 파티 번호


void DFS(int cur) // 현재 탐색하는 사람 번호를 인자로 받음
{
    // 진실을 아는 상태
    // cur 번호 사람이 참석하는 파티를 순회
    for (auto nxt : party_n[cur])
    {
        // 만약 이미 진실을 말한 파티라면 continue
        if (T_party[nxt])
            continue;
        T_party[nxt] = true;
        // nxt 파티에 참석자들을 모두 진실을 아는 사람으로 만들고 DFS 재귀 호출
        for (auto i : people_n[nxt])
        {
            if (T_people[i])
                continue;
            T_people[i] = true;
            DFS(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    int n;
    cin >> n; // 진실을 아는 사람 수
    while (n--)
    {
        int i;
        cin >> i;
        T_people[i] = true;
    }
    for (int i = 0;i < M;i++)
    {
        cin >> n; // 파티 참석 인원
        while (n--)
        {
            int j;
            cin >> j;
            people_n[i].push_back(j);
            party_n[j].push_back(i);
        }
    }
    for (int i = 1;i <= N;i++)
    {
        if (!T_people[i])
            continue;
        DFS(i);
    }
    cout << count(T_party , T_party + M , false);
}