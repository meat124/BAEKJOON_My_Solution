#include<bits/stdc++.h>
using namespace std;
int G , P;
int arr[100005];
vector<int> p(100005);
int result;

int Find(int x)
{
    // p[x] == x 이면 아직 도킹되지 않은 게이트이다.
    if (x == p[x])
        return x; // 도킹되지 않은 게이트를 리턴
    return p[x] = Find(p[x]); // 경로 압축하며 진행
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> G >> P;
    for (int i = 1;i <= G;i++)
        p[i] = i;
    for (int i = 0;i < P;i++)
        cin >> arr[i];

    for (int i = 0;i < P;i++)
    {
        int root = Find(arr[i]);
        if (!root) // 만약 루트가 0이면 비행기를 더 이상 넣을 수 없다는 의미이므로 break;
            break;
        result++; // 비행기 도킹 추가
        p[root] = Find(root - 1); // 하나 작은 게이트의 부모로 부모를 바꾼다.
    }
    cout << result;
}