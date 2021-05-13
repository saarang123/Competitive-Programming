#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
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

const int N = 2e5+5;
int a[N];
map<ll,ll> dp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k;
    cin >> n;
    RE(i,n)
    {
        cin >> a[i];
    }

    RE(i,n)
    {
        dp[a[i]] = dp[a[i]-1]+1;
    }
    ll m=-1,ed=0;
    RE(i,n)
    {
        if(dp[a[i]]>m)
        {
            m = dp[a[i]];
            ed = a[i];
        }
    }
    cout << m << "\n";
    vector<ll> sol;
    FO(i,n)
    {
        if(a[i]==ed)
        {
            ed--;
            sol.pb(i);
        }
    }
    reverse(sol.begin(), sol.end());
    REP(i,0, sol.size()-1)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
    return 0;
}
