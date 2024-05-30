#include<bits/stdc++.h>
using namespace std;
const int dim = 100002;
ifstream fin ("bleach.in");
ofstream fout("bleach.out");
priority_queue<int, vector<int>, greater<int>> pq; ///pq de minime

int main ()
{
    int n, k, x;
    long long minim = 0, putere = 0;
    fin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        fin >> x;
        pq.push(x);
    }
    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        if (x > putere)
        {
            minim += x - putere;
            putere = x;
        }
        putere += x;
    }
    fout << minim << '\n';
}

/*
caz
5 3
1 5 9 3 4
Raspuns = 2
*/
