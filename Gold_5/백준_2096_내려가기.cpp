#include<bits/stdc++.h>
using namespace std;
int N;
struct row
{
    int a , b , c;
    row();
    row(int a , int b , int c) : a(a) , b(b) , c(c) {}

    void change(int a1 , int b1 , int c1)
    {
        a = a1;
        b = b1;
        c = c1;
    }
};
deque<row> board_max , board_min;

void Fill_Max(row& A , row& B)
{
    B.a = max(A.a + B.a , A.b + B.a);
    B.b = max(A.a + B.b , max(A.b + B.b , A.c + B.b));
    B.c = max(A.b + B.c , A.c + B.c);
}

void Fill_Min(row& A , row& B)
{
    B.a = min(A.a + B.a , A.b + B.a);
    B.b = min(A.a + B.b , min(A.b + B.b , A.c + B.b));
    B.c = min(A.b + B.c , A.c + B.c);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int a , b , c;
    cin >> a >> b >> c;
    row tmp(a , b , c);
    board_max.push_back(tmp);
    board_min.push_back(tmp);
    for (int i = 0;i < N - 1;i++)
    {
        cin >> a >> b >> c;
        tmp.change(a , b , c);
        board_max.push_back(tmp);
        board_min.push_back(tmp);
        Fill_Max(board_max.front() , board_max.back());
        Fill_Min(board_min.front() , board_min.back());
        board_max.pop_front();
        board_min.pop_front();
    }
    cout << max(board_max.back().a , max(board_max.back().b , board_max.back().c)) << " ";
    cout << min(board_min.back().a , min(board_min.back().b , board_min.back().c));
}