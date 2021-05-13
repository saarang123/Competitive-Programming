#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<pii> v(n);
        for(i=0; i<n; i++)
        {
            cin >> j >> k;
            v[i] = mp(j,k);
        }
        int flag=1;
        pii pres = mp(0,0);
        sort(v.begin(), v.end());
        for(i=0; i<n; i++)
        {
            j = v[i].f-pres.f;
            k = v[i].ss-pres.ss;
            if(j<0 || k<0) { flag=0; break;}
            pres = v[i];
        }
        if(!flag)
        {
            cout << "NO\n"; continue;
        }
        cout << "YES\n";
        pres = mp(0,0);
        for(i=0; i<n; i++)
        {
            j = v[i].f-pres.f;
            k = v[i].ss-pres.ss;
            while(j--) cout << "R";
            while(k--) cout << "U";
            pres = v[i];
        }
        cout << "\n";
    }
    return 0;
}
