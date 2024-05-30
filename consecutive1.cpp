#include<bits/stdc++.h>
using namespace std;
const int dim = 100002;
int poz_fv[dim]; ///cea mai din dreapta pozitie pe care apare pana in momentul parcurgerii elementul x
int n,poz_distinct[dim],minim[18][dim],maxim[18][dim], put[dim],doi[20];;

void precalculare ()
{
    int niv=1,nr=2;
    while (nr<=n)
    {
        for (int i=1;i<=n-nr+1;i++)
        {
            minim[niv][i]=min(minim[niv-1][i],minim[niv-1][i+nr/2]);
            maxim[niv][i]=max(maxim[niv-1][i],maxim[niv-1][i+nr/2]);
        }
        nr*=2;
        niv++;
    }
}


int main ()
{
    int x, q, st, dr;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        minim[0][i] = x;
        maxim[0][i] = x;
        poz_distinct[i] = max(poz_distinct[i - 1], poz_fv[x] + 1);
        poz_fv[x] = i;
    }
    precalculare();
    int nr = 1, k = 0;
    doi[0]=1;
    for (int i=1;i<=n;i++)
    {
        if (nr*2==i)
        {
            nr*=2,++k;
            doi[k]=nr;
        }
        put[i]=k;
    }
    cin >> q;
    while (q--)
    {
        cin >> st >> dr;

        int minim_interval = min(minim[put[dr-st+1]][st],minim[put[dr-st+1]][dr-doi[put[dr-st+1]]+1]);
        int maxim_interval = max(maxim[put[dr-st+1]][st],maxim[put[dr-st+1]][dr-doi[put[dr-st+1]]+1]);

        if (maxim_interval - minim_interval == dr - st && poz_distinct[dr] <= st)
            cout << 1;
        else    cout << 0;
    }
}
