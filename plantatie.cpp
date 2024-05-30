#include <bits/stdc++.h>
using namespace std;
ifstream fin ("plantatie.in");
ofstream fout("plantatie.out");
int a[10][502][502],n,doi[10],put[502];

void cit ()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            fin>>a[0][i][j];
}

void precalc ()
{
    int exp=1,x=2,i,j;
    while (x<=n)
    {
        for (i=1;i<=n-x+1;i++)
            for (j=1;j<=n-x+1;j++)
                a[exp][i][j]=max(a[exp-1][i][j],max(a[exp-1][i][j+x/2],max(a[exp-1][i+x/2][j],a[exp-1][i+x/2][j+x/2])));
        x*=2,exp++;
    }
    x=2,exp=1;
    doi[0]=1,doi[1]=2;
    for (i=2;i<=n;i++)
        {if (x*2==i)
            x*=2,doi[++exp]=x;
         put[i]=exp;
        }
}

void query (int q)
{
    for (;q>0;q--)
    {
        int x,y,l;
        fin>>x>>y>>l;
        int dim=put[l];
        int powr=doi[dim];
        fout<<max(a[dim][x][y],max(a[dim][x][y-powr+l],max(a[dim][x+l-powr][y],a[dim][x+l-powr][y+l-powr])))<<'\n';
    }
}

int main()
{
    int q;
    fin>>n>>q;
    cit();
    precalc ();
    query(q);
    return 0;
}
