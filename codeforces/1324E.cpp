#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define double long double
#define f first
#define ss second
#define mp make_pair
#define pb push_back

#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int N = 2e3+5;
int dp[N][N] = {0};
int a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m,l,r,h;
    cin >> n >> h >> l >> r;
    RE(i,n) cin >> a[i];
    REP(i,0,h-1)
    {
        if((i+a[n])%h>=l && (i+a[n])%h<=r) dp[n][i] = 1;
        if((i+a[n]-1)%h>=l && (i+a[n]-1)%h<=r) dp[n][i] = 1;
    }

    REB(i,n-1,1)
    {
        REP(j,0,h-1)
        {
            int p=0,p1=0;
            if((j+a[i])%h>=l &&(j+a[i])%h<=r) p = 1;
            if((j+a[i]-1)%h>=l && (j+a[i]-1)%h<=r) p1 = 1;
            dp[i][j] = max(p+dp[i+1][(j+a[i])%h], p1+dp[i+1][(j+a[i]-1)%h]);
        }
    }
    cout << dp[1][0] << "\n";
    return 0;
}
