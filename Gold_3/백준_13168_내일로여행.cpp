#include<bits/stdc++.h>
using namespace std;
int N , M , K , R;
// 내일로 티켓을 사지 않은 경우 최소 비용 배열
double adj[105][105];
// 내일로 티켓을 살 경우 최소 비용 배열
double discount_adj[105][105];
// 전체 도시 이름, 여행할 도시 이름
vector<string> cities;
vector<int> to_go;
// 여행 시작하는 도시 위치
int start;

double Non_Naeilro()
{
    double total_cost = 0;
    for (auto itr = to_go.begin();itr != prev(to_go.end());itr++)
        total_cost += adj[*itr][*next(itr)];
    return total_cost;
}

double Buy_Naeilro()
{
    double total_cost = R;
    for (auto itr = to_go.begin();itr != prev(to_go.end());itr++)
        total_cost += discount_adj[*itr][*next(itr)];
    return total_cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> R;
    for (int i = 0;i < N;i++)
    {
        string str;
        cin >> str;
        // 이름이 같은 도시는 하나로 통일함
        if (find(cities.begin() , cities.end() , str) != cities.end())
            continue;
        cities.push_back(str);
    }
    // 도시 이름 오름차순 정렬
    sort(cities.begin() , cities.end());
    // 여행할 도시의 개수
    cin >> M;
    for (int i = 0;i < M;i++)
    {
        string str;
        cin >> str;
        int a = find(cities.begin() , cities.end() , str) - cities.begin();
        to_go.push_back(a);
    }
    start = to_go[0];
    for (int i = 0;i < N;i++)
    {
        fill(adj[i] , adj[i] + N , 400000000);
        fill(discount_adj[i] , discount_adj[i] + N , 400000000);
        adj[i][i] = 0;
        discount_adj[i][i] = 0;
    }
    // 교통수단의 수
    cin >> K;
    for (int i = 0;i < K;i++)
    {
        string trans , c1 , c2;
        double cost;
        cin >> trans >> c1 >> c2 >> cost;
        int a , b;
        a = find(cities.begin() , cities.end() , c1) - cities.begin();
        b = find(cities.begin() , cities.end() , c2) - cities.begin();
        adj[a][b] = min(adj[a][b] , cost);
        adj[b][a] = min(adj[b][a] , cost);
        if (trans == "Mugunghwa" || trans == "ITX-Saemaeul" || trans == "ITX-Cheongchun")
        {
            discount_adj[a][b] = 0;
            discount_adj[b][a] = 0;
        }
        else if (trans == "S-Train" || trans == "V-Train")
        {
            discount_adj[a][b] = min(discount_adj[a][b] , cost / 2);
            discount_adj[b][a] = min(discount_adj[b][a] , cost / 2);
        }
        else
        {
            discount_adj[a][b] = min(discount_adj[a][b] , cost);
            discount_adj[b][a] = min(discount_adj[b][a] , cost);
        }
    }
    // 플로이드-워셜
    for (int k = 0;k < N;k++)
        for (int i = 0;i < N;i++)
            for (int j = 0;j < N;j++)
            {
                adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
                discount_adj[i][j] = min(discount_adj[i][j] , discount_adj[i][k] + discount_adj[k][j]);
            }
    double non = Non_Naeilro() , buy = Buy_Naeilro();
    if (non > buy)
        cout << "Yes";
    else
        cout << "No";
}