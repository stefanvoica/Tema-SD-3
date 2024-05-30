#include<bits/stdc++.h>
#define int long long
using namespace std;
const int dim = 100005, mod = 1000000007;
int v[dim], p[dim], aint[4*dim + 2];

void update(int nod, int st, int dr, int poz, int val)
{
    if(st==dr)
        aint[nod]=val;
    else
    {
        int mij=(st+dr)/2;
        if(poz<=mij)
            update(nod*2,st,mij,poz,val);
        else
            update(nod*2+1,mij+1,dr,poz,val);
        aint[nod]=max(aint[nod*2],aint[nod*2+1]);
    }
}

int query(int nod, int st, int dr, int l,int r)
{
    if(st==l && dr==r)
        return aint[nod];
    int mij=(st+dr)/2;
    if(r<=mij)
        return query(2*nod,st,mij,l,r);
    else if(l>mij)
        return query(2*nod+1,mij+1,dr,l,r);
    return max(query(2*nod,st,mij,l,mij),query(2*nod+1,mij+1,dr,mij+1,r));
}

int32_t main()
{
    int n,i;
    cin>>n;
    p[1]=1;
    for(i=2; i<=n; i++)
        p[i]=(p[i-1]*2)%mod;
    for(i=1; i<=n; i++)
    {
        cin>>v[i];
        update(1,1,n,i,v[i]);
    }
    int q, l, r;
    cin>>q;
    for(i=1; i<=q; i++)
    {
        cin>>l>>r;
        int val=query(1,1,n,l,r);
        int y=p[r-l+1];
        int z=(val*y)%mod;
        cout<<z<<'\n';
    }
    return 0;
}
