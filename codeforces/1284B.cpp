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

const int N = 1e5+3;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    vector<int> m1, m2;
    set<int> s;
    ll ans = 0,cnt=0;
    RE(i,n)
    {
        int p1 = INF, p2 = 0,prev=-1;
        bool asc = false;
        cin >> t;
        RE(j,t)
        {
            cin >> k;
            if(k>p1) asc = true;
            p1 = min(p1,k);
            p2 = max(p2,k);
        }

        if(asc)
        {
            cnt++;
        }
        else
        {
            m1.pb(p1);
            m2.pb(p2);
        }
    }

    sort(m2.begin(), m2.end());

    for(i=0; i<cnt;i++)
    {
        ans += 2*n-1-2*i;
    }

    for(i=0; i<m1.size(); i++)
    {
        auto lo = upper_bound(m2.begin(), m2.end(), m1[i]);
        auto low = m2.end()-lo;
        //cout << m1[i] << " " << *lo << " " << low << "\n";
        ans+=low;
    }

    cout << ans << "\n";
    return 0;
}
