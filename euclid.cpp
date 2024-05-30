#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
int a[402][402];

int main()
{
    int teste;
    fin >> teste;
    for (int nr = 1; nr <= teste; nr++)
    {
        int m, n, h, w, maxim = 0;
        fin >> m >> n >> h >> w;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                fin >> a[i][j];


        for (int i = 0; i <= m - h; ++i)
            for (int j = 0; j <= n - w; ++j)
            {
                int cmmdc = a[i][j];
                for (int k = i; k <= i + h - 1 && cmmdc > maxim; ++k)
                    for (int l = j; l <= j + w - 1 && cmmdc > maxim; ++l)
                        cmmdc = __gcd(cmmdc, a[k][l]);
                maxim = max(maxim, cmmdc);
            }
        fout << "Case #" << nr << ": " << maxim << endl;
    }

    return 0;
}
