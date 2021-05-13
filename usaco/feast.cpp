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

const int N = 5e6+2;
bool dp[N][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    ll i,j,a,b,t,n;
    cin >> t >> a >> b;
    dp[0][0] = 1;
    for(i=1; i<=t; i++)
    {
        if(i-a>-1) dp[i][0] |= dp[i-a][0];
        if(i-b>-1) dp[i][0] |= dp[i-b][0];
        if(dp[i][0]) dp[i/2][1] |= dp[i][0];
        if(i-a>=0) dp[i][1] |= dp[i-a][1];
        if(i-b>=0) dp[i][1] |= dp[i-b][1];
    }
    for(i=1; i<=t; i++)
    {
        if(dp[i][0]) dp[i/2][1] |= dp[i][0];
        if(i-a>=0) dp[i][1] |= dp[i-a][1];
        if(i-b>=0) dp[i][1] |= dp[i-b][1];
    }
    ll mx = 0;
    //RE(i,t) cout << i << " " << dp[i][0] << " " << dp[i][1] << "\n";
    for(i=1; i<=t; i++)
    {
        if(dp[i][0]) mx = max(mx,i);
        if(dp[i][1]) mx = max(mx,i);
    }
    cout << mx << "\n";
    return 0;
}
