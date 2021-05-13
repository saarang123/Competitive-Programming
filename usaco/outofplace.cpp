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
    //freopen("input.txt", "r", stdin);
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");
    int n,i,j,t,k;
    fin >> n;
    int a[n], b[n];
    for(i=0; i<n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    int swaps = -1;
    for(i=0; i<n; i++)
    {
        if(b[i]!=a[i])
            swaps++;
    }
    swaps = max(swaps, 0);
    fout << swaps << "\n";
    return 0;
}
