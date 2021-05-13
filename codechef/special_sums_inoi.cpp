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

/*
    @Author: Saarang Srinivasan
    Handle: saarang123 on all platforms.
*/

const int N = 1e6+3;
ll a[N], b[N], pre[N]={0};
pair<ll, pii> dp[N], dp2[N];

ll ssum(int i, int j, int n)
{
    if(i==j)
        return a[i];
    if(i<j)
        return a[i] + a[j] + pre[j-1]-pre[i];
    return a[i]+a[j] + pre[j-1] + pre[n]-pre[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n)
    {
        cin >> a[i];
    }
    RE(i,n)
    {
        cin >> b[i];
        pre[i]=b[i]+pre[i-1];
    }

    RE(i,n)
    {
        dp[i] = mp(a[i], mp(i,i));
        dp2[i] = mp(a[i], mp(i,i));
    }
    REB(i,n-1,1)
    {
        dp[i].f = max(ssum(i, dp[i+1].ss.ss,n),max(dp[i+1].f, dp[i].f));
        if(dp[i].f==ssum(i, dp[i+1].ss.ss,n))
        {
            dp[i].ss = mp(i,dp[i+1].ss.ss);
        }
        else if(dp[i].f==dp[i+1].f)
        {
            dp[i].ss = dp[i+1].ss;
        }
        else
        {
            dp[i].ss = mp(i,i);
        }
    }

    RE{(i,1,n)
    {
        dp[i].f = max(ssum(i, dp[i-1].ss.ss,n),max(dp[i-1].f, dp[i].f));
        if(dp[i].f==ssum(i, dp[i-1].ss.ss,n))
        {
            dp[i].ss = mp(i,dp[i-1].ss.ss);
        }
        else if(dp[i].f==dp[i-1].f)
        {
            dp[i].ss = dp[i-1].ss;
        }
        else
        {
            dp[i].ss = mp(i,i);
        }
    }
    cout << ans << "\n";
    return 0;
}
