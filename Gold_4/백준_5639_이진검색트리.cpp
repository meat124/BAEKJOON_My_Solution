#include<bits/stdc++.h>
using namespace std;
vector<int> preorder;

// 탐색할 범위를 인자로 받는다.
void Post_Order(int st , int en)
{
    // st 와 en 이 역전된 경우 return
    if (st >= en)
        return;
    // st 와 en 사이에 요소가 없는 경우, preorder[st] 를 출력
    if (st == en - 1)
    {
        cout << preorder[st] << "\n";
        return;
    }
    int idx = st + 1;
    // en 보다 작으면 반복
    while (idx < en)
    {
        // 처음으로 preorder[st] 보다 커지는 곳 발견하면 탈출
        if (preorder[st] < preorder[idx])
            break;
        idx++;
    }
    // Post_Order 이므로 재귀함수문 두 개를 먼저 작성하고 마지막에 값 출력
    Post_Order(st + 1 , idx);
    Post_Order(idx , en);
    cout << preorder[st] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n)
        preorder.push_back(n);

    Post_Order(0 , preorder.size());
}