#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n], m = INF+5;
        for(i=0; i<n; i++)
        {
            cin >> a[i];
            m = min(a[i], m);
        }
        int ans = 0;
        vector<pair<int, int> > v;
        for(i=0; i<n; i++)
        {
            j = a[i];
            k=1;
            while(a[i+1]==j && i<n)
            {
                i++;
                k++;
            }
            v.pb(mp(j,k));
        }

        cout << ans << "\n";

    }
    return 0;
}
