#include<bits/stdc++.h>
using namespace std;

ifstream fin ("proc2.in");
ofstream fout("proc2.out");


struct cmp
{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        return p1.first > p2.first;
    }
};


priority_queue<int, vector<int>, greater<int>> procesor; ///pq de minime pe pozitiile procesoarelor
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> introduce; ///pq pentru procesoarele ocupate sortate dupa momentul cand trebuie introduse
///pair<int,int> -> timp, procesor

int main ()
{
    int n, m, start, durata;
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        procesor.push(i);
    for (int i = 1; i <= m; i++)
    {
        fin >> start >> durata;

        while (!introduce.empty() && introduce.top().first <= start)
        {
            procesor.push(introduce.top().second);
            introduce.pop();
        }

        fout << procesor.top() << '\n';
        introduce.push({start + durata, procesor.top()});
        procesor.pop();
    }
    return 0;
}
