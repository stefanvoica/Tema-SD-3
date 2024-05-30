#include <bits/stdc++.h>
using namespace std;
const int dim = 100002;

struct elem
{
    int a, b;
} v[dim];

inline bool cmp (const elem &a1, const elem &a2)
{
    if (a1.a == a2.a)
        return a1.b < a2.b;
    return a1.a < a2.a;
}

int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin >> v[i].a >> v[i].b;
        if (v[i].a > v[i].b)
            swap(v[i].a, v[i].b);
    }
    sort(v + 1, v + n + 1, cmp);
    int sol = v[n].a - v[1].a, minim = INT_MAX, maxim = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        if (v[i].b > maxim)
            maxim = v[i].b;
        if (v[i].b < minim)
            minim = v[i].b;
        int newmax = max(maxim, v[n].a), newmin = min(minim, v[i + 1]. a);
        sol = min(sol, newmax - newmin);
    }

    ///Pt al n-lea element
    if (v[n].b > maxim)
        maxim = v[n].b;
    if (v[n].b < minim)
        minim = v[n].b;
    sol = min(sol, maxim - minim);
    cout << sol;
    return 0;
}
