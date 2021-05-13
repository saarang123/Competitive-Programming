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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const int N = 2e5+4;
vector<vector<pll> > graph(N);
int ans[N] = {1};

/*
pair<set<ll>,ll> dfs(ll src, ll l)
{
    set<int> s;
    int left = 0;
    for(pii adj:graph[src])
    {
        ll dist = adj.ss, ad = adj.f;
        pair<set<ll>, ll> lol = dfs(ad, l);
        merge(lol.f.begin(), lol.f.end(), s.begin(), s.end(), inserter(s, s.end()));
        left = lol.s;

    }
}
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("runaway.in");
    ofstream fout("runaway.out");
    ll l,n,i,j,t,k,m;
    cin >> n >> l;
    RE(i,n-1)
    {
        cin >> j >> k;
        graph[j].pb(mp(i,k));
        ans[i] = 1;
    }
    ans[n] = 1;

    return 0;
}
