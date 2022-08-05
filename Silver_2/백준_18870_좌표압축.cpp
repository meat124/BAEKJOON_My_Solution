#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int N;
vector<int> coord(1000005);
vector<int> sorted_coord;
set<int> remove_overlap;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        cin >> coord[i];
        remove_overlap.insert(coord[i]);
    }
    for (auto i : remove_overlap)
        sorted_coord.push_back(i);
    for (int i = 0;i < N;i++)
        cout << lower_bound(sorted_coord.begin() , sorted_coord.end() , coord[i]) - sorted_coord.begin() << " ";
}