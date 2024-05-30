#include <bits/stdc++.h>
using namespace std;
ifstream fin ("timbre.in");
ofstream fout("timbre.out");
const int dim = 10005;
priority_queue<int, vector<int>, greater<int>> pq; ///pq de minime pe costuri
struct elem
{
    int maxim, cost;
}v[dim];

bool cmp (const elem &a, const elem &b)
{
    return a.maxim > b.maxim;
}

int main()
{
    int n, m, k, sol = 0;
    fin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        fin >> v[i].maxim >> v[i].cost;
    sort(v + 1, v + m + 1, cmp); ///sortez dupa marginea superioara
    int i = 1; ///indicele de parcurgere prin vectorul v
    while (n > 0)
    {
        while (i <= m && v[i].maxim >= n)
        {
            pq.push(v[i].cost);
            i++;
        }
        sol = sol + pq.top();
        pq.pop();
        n = n - k;
    }
    fout << sol;
    return 0;
}

