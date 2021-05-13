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
    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");
    //freopen("input.txt", "r", stdin);
    int n,i,j,b,k;
    fin >> n >> k >> b;
    int a[n+1];
    for(i=0; i<=n; i++)
        a[i]=0;
    for(i=1; i<=b; i++)
    {
        fin >> j;
        a[j] = 1;
    }
    for(i=1; i<=n ; i++)
        a[i]+=a[i-1];
    int m = 100000000;
    for(i=1; i<=n; i+=1)
    {
        if(i+k>n) break;
        int pres = a[i+k]-a[i];
        if(pres<m)
            m = pres;

    }
    fout << m << "\n";
    return 0;
}
