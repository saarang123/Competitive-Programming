#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    int i,j,n, m, c, a[151], b[151], g[101];
    fin >> n >> m;
    for(i=1; i<=m; i++)
    {
        fin >> a[i] >> b[i];
        if(b[i]<a[i])  swap(a[i],b[i]);
    }
    for(i=1; i<=n; i++)
    {
        for(c=1; c<=4; c++)
        {
            bool ok = true;
            for(j=1; j<=m; j++)
            {
                if(b[j]==i && g[a[j]]==c) ok = false;
            }
            if(ok) break;
        }
        g[i] = c;
        fout << c;
    }
    fout << "\n";
    return 0;
}
