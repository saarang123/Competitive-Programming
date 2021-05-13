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
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");
    int n, i, j;
    fin >> n;
    int a[n][n];
    for(i=0; i<n; i++)
    {
        j=i;
        int p;
        fin >> p;
        for(int k=0; k<n; k++)
        {
            j=j%n;
            a[k][j] = p;
            j++;
        }
    }
    /*
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    */
    int ans = 1000000000, pres=0;
    for(i=0; i<n; i++)
    {
        pres=0;
        for(j=0; j<n; j++)
            pres+=a[i][j]*j;
        //cout << pres << endl;
        if(pres<ans)
            ans = pres;
    }
    fout << ans << endl;
    return 0;
}
