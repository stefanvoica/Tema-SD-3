#include <bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin ("pikachu.in");
ofstream fout("pikachu.out");
const int dim = 100002;
unordered_map <int, int> nor, inv;
int n, val, v[dim], w[dim], pw=1, logn, put[99];

struct el
{
    int nr, s;
} aib[dim];

void update (int poz, int v1, int v2)
{
    for (int i=poz; i<=val; i += (i&-i))
    {
        aib[i].nr += v1;
        aib[i].s += v2;
    }
}

el query (int poz)
{
    el sum={0,0};
    for (int i=poz; i>=1; i -= (i&-i))
    {
        sum.s += aib[i].s;
        sum.nr += aib[i].nr;
    }
    return sum;
}

int q3 (int x)
{
    int sum=0,pos=0;
    for (int i=logn; i>=0; i--)
    {
        if (pos+put[i] < val && sum+aib[pos+put[i]].nr < x)
        {
            sum+=aib[pos+put[i]].nr;
            pos+=put[i];
        }
    }
    return pos + 1;
}

void solve ()
{
    int k, mini = 1e18, stot = 0;
    fin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        fin >> v[i];
        w[i] = v[i];
    }
    sort (w + 1, w + n + 1);
    for (int i = 1; i <= n; i++)
        if (w[i] != w[i-1])
        {
            nor[w[i]] = ++val;
            inv[val] = w[i];
        }

    while (pw<=val)
    {
        put[logn]=pw;
        pw*=2;
        logn++;
    }
    logn--;
    pw/=2;

    for (int i = 1; i < k; i++)
        update(nor[v[i]], 1, v[i]), stot += v[i];

    for (int i = 1; i <= n - k + 1; i++)
    {
        //aduc la v[i+k/2]
        int med = k / 2 + 1;
        if (i != 1)
            stot-=v[i-1], update(nor[v[i-1]], -1, -v[i-1]);
        update(nor[v[i+k-1]], 1, v[i+k-1]);
        stot += v[i+k-1];

        int val_med = q3(med);
        el small = query(val_med);
        int res = small.nr * inv[val_med] - small.s;
        res += (stot - small.s) - (k - small.nr) * inv[val_med];
        mini = min(mini, res);
    }
    fout<<mini<<'\n';
}

int32_t main()
{
    solve();
}
