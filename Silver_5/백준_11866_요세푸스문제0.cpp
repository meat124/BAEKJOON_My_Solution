#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DelPeople(queue<int> &q1, queue<int> &q2, int k)
{
    while (!q1.empty())
    {
        for (int i = 0; i < k - 1; i++) // 만약 k == 1 이면 for 문 실행되지 않음
        {
            q1.push(q1.front()); // 프론트 원소를 다시 푸시
            q1.pop();            // 프론트 원소 팝
        }
        q2.push(q1.front());
        q1.pop(); // 푸시 없이 팝
    }
}

void PrintQueue(queue<int> &q)
{
    int n = q.size() - 1;
    cout << "<";
    for (int i = 0; i < n; i++)
    {
        cout << q.front();
        q.pop();
        cout << ", ";
    }
    cout << q.front();
    q.pop();
    cout << ">";
}

int main()
{
    int N, K;
    cin >> N >> K;

    // 원을 이루며 앉아있는 형태의 벡터
    // 사람이 제거되면 빈공간을 뒤에서 내려와서 채운다.
    queue<int> que1;
    queue<int> que2;

    for (int i = 1; i <= N; i++)
        que1.push(i);
    DelPeople(que1, que2, K);

    PrintQueue(que2);
}