#include <bits/stdc++.h>
#define int long long
using namespace std;
int aib[1000002],suma[1000002],pw=1,logn,put[100];

void update (int poz, int val)
{
    for (int i=poz; i<=1e6; i += (i&-i))
    {
        aib[i] += val;
        suma[i] += poz;
    }
}

int query1 (int poz)
{
    int sum=0;
    for (int i=poz; i>=1; i -= (i&-i))
        sum += aib[i];
    return sum;
}

int query2 (int poz)
{
    int sum=0;
    for (int i=poz; i>=1; i -= (i&-i))
        sum += suma[i];
    return sum;
}

int q3 (int val)
{
    int sum=0,pos=0;
    for (int i=logn; i>=0; i--)
    {
        if (pos+put[i] < 1e6 && sum+aib[pos+put[i]] < val)
        {
            sum+=aib[pos+put[i]];
            pos+=put[i];
        }
    }
    return pos;
}

int32_t main()
{
    int q, x, tip;
    while (pw<=1e6)
    {
        put[logn]=pw;
        pw*=2;
        logn++;
    }
    logn--;
    pw/=2;
    cin >> q;
    while (q--)
    {
        cin >> tip >> x;
        if (tip == 1)
            update(x, 1);
        else {
            int poz = q3(x);
            int rez = query2(poz) + (x-query1(poz))*(poz+1);
            cout << rez<<'\n';
        }
    }
    return 0;
}
