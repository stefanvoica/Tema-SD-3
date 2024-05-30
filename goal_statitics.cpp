#include<bits/stdc++.h>
using namespace std;
int aib[1000002];

void update (int poz,int val)
{
    for (int i=poz;i<=n;i+=(i&-i))
        aib[i]+=val;
}

int query (int poz)
{
    int sol=0;
    for (int i=poz;i>0;i-=(i&-i))
        sol+=aib[i];
    return sol;
}

int main ()
{

}
