#include<iostream>
using namespace std;
int N;
struct node
{
    char left , right;
};
node board[30];

void Preorder_traversal(char c)
{
    if (c == '.')
        return;
    cout << c;
    Preorder_traversal(board[c - 'A'].left);
    Preorder_traversal(board[c - 'A'].right);
}
void Inorder_traversal(char c)
{
    if (c == '.')
        return;
    Inorder_traversal(board[c - 'A'].left);
    cout << c;
    Inorder_traversal(board[c - 'A'].right);
}
void Postorder_traversal(char c)
{
    if (c == '.')
        return;
    Postorder_traversal(board[c - 'A'].left);
    Postorder_traversal(board[c - 'A'].right);
    cout << c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        char a , b , c;
        cin >> a >> b >> c;
        board[a - 'A'].left = b;
        board[a - 'A'].right = c;
    }
    Preorder_traversal('A');
    cout << "\n";
    Inorder_traversal('A');
    cout << "\n";
    Postorder_traversal('A');
}