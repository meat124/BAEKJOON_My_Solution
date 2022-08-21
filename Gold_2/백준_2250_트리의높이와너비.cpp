#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// 노드의 개수가 열의 크기, 트리의 깊이가 행의 크기가 된다.
int N , root = 1 , cur = 1;
int lc[10005]; // 왼쪽 자식 노드
int rc[10005]; // 오른쪽 자식 노드
int p[10005]; // 부모 노드
int lb[10005]; // 각 레벨의 가장 왼쪽 값
int ub[10005]; // 각 레벨의 가장 오른쪽 값
int width[10005]; // width[i] = ub[i] - lb[i]
int result_width = 1 , result_level = 1;

void Inorder(int n , int l)
{
    // left subtree
    if (lc[n] > 0)
        Inorder(lc[n] , l + 1);
    // current node visit
    lb[l] = min(lb[l] , cur);
    ub[l] = max(ub[l] , cur++);
    width[l] = ub[l] - lb[l] + 1;
    // right subtree
    if (rc[n] > 0)
        Inorder(rc[n] , l + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        int a , b , c;
        cin >> a >> b >> c;
        lc[a] = b , rc[a] = c;
        if (b != -1)
            p[b] = a;
        if (c != -1)
            p[c] = a;
    }
    fill(lb , lb + 10005 , 0x7FFFFFFF);
    // 루트 탐색
    while (p[root])
        root = p[root];
    Inorder(root , 1);
    for (int i = 1;i <= N;i++)
    {
        int tmp = ub[i] - lb[i] + 1;
        if (tmp > result_width)
        {
            result_width = tmp;
            result_level = i;
        }
    }
    for (int i = 1;i <= N;i++)
        if (width[i] > result_width)
        {
            result_width = width[i];
            result_level = i;
        }
    cout << result_level << " " << result_width;
}