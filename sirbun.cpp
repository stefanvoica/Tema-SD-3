#include <bits/stdc++.h>
using namespace std;
ifstream fin("sirbun.in");
ofstream fout("sirbun.out");
const int dim = 100002;
int n, v[dim];
int aint[4 * dim], lazy[4 * dim];

void update(int x, int y, int val, int i, int l, int r) {

    if (y < l || r < x)
        return;
    if (lazy[i] != 0) {
        aint[i] += lazy[i];
        if (l != r) {
            lazy[i * 2] += lazy[i],
            lazy[i * 2 + 1] += lazy[i];
        }
        lazy[i] = 0;
    }
    if (x <= l && r <= y) {
        aint[i] += val;
        if (l != r) {
            lazy[i * 2] += val,
            lazy[i * 2 + 1] += val;
        }
        return;
    }

    int m = (l + r) / 2;
    update(x, y, val, 2 * i, l, m);
    update(x, y, val, 2 * i + 1, m + 1, r);

    aint[i] = min(aint[2 * i] + lazy[2 * i], aint[2 * i + 1] + lazy[2 * i + 1]);
}

int minim(int x, int y, int add = 0, int i = 1, int l = 1, int r = n) {
    if (y < l || r < x)
        return INT_MAX;
    add += lazy[i];
    if (x <= l && r <= y)
        return add + aint[i];
    int m = (l + r) / 2;
    return min(minim(x, y, add, 2 * i, l, m), minim(x, y, add, 2 * i + 1, m + 1, r));
}

int main() {
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> v[i];
        update(i, i, i, 1, 1, n);
    }
    int last = 1;
    long long sol = 0;
    for (int i = 1; i <= n; i++) {
        update(v[i], n, -1, 1, 1, n);
        while (minim(1, n) < 0 && last < i) {
            update(v[last], n, 1, 1, 1, n);
            last++;
        }
        sol = sol + (i - last + 1);
    }
    fout << sol;
    return 0;
}
