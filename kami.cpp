#include<bits/stdc++.h>
using namespace std;
ifstream fin ("kami.in");
ofstream fout("kami.out");
const int dim = 100002;
int v[dim];

int32_t main ()
{
    int n, q, tip, x, val, maxim = INT_MIN;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> v[i];
        maxim = max(maxim, v[i]);
    }
    fin >> q;
    while (q--)
    {
        fin >> tip >> x;
        if (tip == 0)
        {
            fin >> val;
            v[x] = val;
        }
        else
        {
            long long sum = v[x];
            int  niv = x - 1;
            while (niv != 0 && v[niv] * 1LL < sum)
            {
                sum += v[niv];
                niv--;
                if (sum > maxim)
                    niv = 0;
            }
            fout << niv << '\n';
        }
    }
}
/*
3  -> niv 5
2  -> niv 4
1
4
10  -> niv 1
*/
