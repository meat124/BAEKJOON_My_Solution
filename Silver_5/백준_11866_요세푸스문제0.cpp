#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DelPeople(queue<int> &q1, queue<int> &q2, int k)
{
    while (!q1.empty())
    {
        for (int i = 0; i < k - 1; i++) // ���� k == 1 �̸� for �� ������� ����
        {
            q1.push(q1.front()); // ����Ʈ ���Ҹ� �ٽ� Ǫ��
            q1.pop();            // ����Ʈ ���� ��
        }
        q2.push(q1.front());
        q1.pop(); // Ǫ�� ���� ��
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

    // ���� �̷�� �ɾ��ִ� ������ ����
    // ����� ���ŵǸ� ������� �ڿ��� �����ͼ� ä���.
    queue<int> que1;
    queue<int> que2;

    for (int i = 1; i <= N; i++)
        que1.push(i);
    DelPeople(que1, que2, K);

    PrintQueue(que2);
}