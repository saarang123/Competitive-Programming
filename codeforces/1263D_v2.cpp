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

const int N = 2e5+4;
vi graph[N], letter[27];
int vis[N] = {0};

void dfs(int v)
{
    if(vis[v]) return;
    vis[v] = 1;
    for(auto u: graph[v])
        dfs(u);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    RE(p,n)
    {
        string s;
        cin >> s;
        for(char c: s)
        {
            letter[c-'a'].pb(p);
        }
    }

    REP(i,0,26)
    {
        j = 0;
        while(j+1<letter[i].size())
        {
            int v = letter[i][j];
            int u = letter[i][j+1];
            graph[v].pb(u);
            graph[u].pb(v);
            j++;
        }
    }

    int ans = 0;
    RE(i,n)
    {
        if(vis[i]) continue;
        ans++;
        dfs(i);
    }
    cout << ans << "\n";

    return 0;
}
