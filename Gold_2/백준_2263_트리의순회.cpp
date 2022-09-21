#include<bits/stdc++.h>
using namespace std;
int n;
int Index[100005]; // postorder 의 값의 인덱스를 저장하는 배열
int inorder[100005];
int postorder[100005];
// 트리는 현재 이진트리이다.
// 인오더 : 왼쪽 하위 트리를 방문 후 뿌리를 방문
// 포스트오더 : 하위 트리 모두 방문 후 뿌리를 방문
// 프리오더 : 뿌리를 먼저 방문
// 인오더와 포스트 오더를 알고 있을 때 프리오더를 구하여라
// 즉 인오더와 포스트 오더를 이용하여 트리를 재구성한다.

void Pre_Order(pair<int , int> in , pair<int , int> post)
{
    // 만약 범위가 역전되면 더 이상 분할 불가한 경우이므로 return
    if (in.first > in.second || post.first > post.second)
        return;

    int root_index = Index[postorder[post.second]];
    int left_size = root_index - in.first;
    int right_size = in.second - root_index;
    cout << inorder[root_index] << " ";

    Pre_Order({ in.first, root_index - 1 } , { post.first, post.first + left_size - 1 });
    Pre_Order({ root_index + 1, in.second } , { post.first + left_size, post.second - 1 });
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> inorder[i];
        Index[inorder[i]] = i;
    }
    for (int i = 1;i <= n;i++)
        cin >> postorder[i];
    Pre_Order({ 1,n } , { 1,n });
}