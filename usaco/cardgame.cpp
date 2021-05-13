#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k;
    fin >> n;
    vector<bool> all(2*n);
    vector<int> a(n), b;
    for(i=0; i<n; i++)
    {
        fin >> a[i];
        a[i]--;
        all[a[i]] = 1;
    }
    for(i=0; i<2*n; i++)
    {
        //cout << all[i] << " ";
        if(!all[i])
            b.pb(i);
    }

    reverse(a.begin(), a.begin()+n);
    sort(a.begin(), a.begin()+n/2);
    sort(a.begin()+n/2, a.end());

    /*
    for(i=0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
    for(i=0; i<n; i++)
        cout << b[i] << " ";
    cout << "\n";
    */

    int ans = 0;
    for(i=n/2, j=n/2; i<n, j<n; j++, i++)
    {
        while(j<n && b[j]<a[i])
            j++;
        if(j==n)
            break;
        //cout << b[j] << " " << a[i] << "\n";
        ans++;
    }

    for(i=n/2-1, j=n/2-1; j>=0, i>=0; j--,i--)
    {
        while(j>-1 && b[j]>a[i])
            j--;

        if(j==-1)
            break;
        //cout << b[j] << " " << a[i] << "\n";
        ans++;
    }
    fout << ans << "\n";
    return 0;
}
