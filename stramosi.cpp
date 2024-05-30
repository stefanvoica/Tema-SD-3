#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
#define dim 250002
using namespace std;
ifstream fin ("stramosi.in");
ofstream fout("stramosi.out");
int str[20][dim];

int sol (int niv,int &x,int k)
{
    if (k!=0)
    {
    if (k%2==1)
        x=str[niv][x];
    sol(niv+1,x,k/2);
    }
}

int32_t main()
{
    int n,i,j,m,x,k;
    fin>>n>>m;
    for (i=1;i<=n;i++)
        fin>>str[0][i];
    for (i=1;i<=18;i++)
    {
       for (j=1;j<=n;++j)
            str[i][j]=str[i-1][str[i-1][j]];
    }
    while (m--)
    {
        fin>>x>>k;
        sol(0,x,k);
        fout<<x<<'\n';
    }
    return 0;
}
