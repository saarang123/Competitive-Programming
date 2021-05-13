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
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int N = 2e5+5;
vii graph(N);
int col[N], ans[N], dp[N];

void dfs(int v, int p)
{
    dp[v] = col[v];
    for(int u: graph[v])
    {
        if(u==p) continue;
        dfs(u,v);
        dp[v] += max(0,dp[u]);
    }
}

void sol(int v, int p)
{
    ans[v] = dp[v];
    for(int u: graph[v])
    {
        if(u==p) continue;
        //Rerooting the graph rooted initially at v to u.
        //Rerooting to u only will make changes in dp[u] and dp[v].
        //Ensuring the changes made are correct/the right answer.
        dp[v] -= max(dp[u],0); //u is no long in subtree of v.
        dp[u] += max(dp[v],0); //Adding v if possible to subtree of u.
        sol(u,v);  //re-rooting again in its children.
        dp[u] -= max(dp[v],0); //Removing changes made.
        dp[v] += max(dp[u],0); //Removing changes made.
    }
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
        cin >> j;
        if(!j) col[i] = -1;
        else col[i] = 1;
    }
    RE(i,n-1)
    {
        cin >> j >> k;
        graph[j].pb(k);
        graph[k].pb(j);
    }

    dfs(1,-1); //Rooting initially at node 1.
    sol(1,-1); //Re-rooting to each node and making changes to the required ones.
    RE(i,n) cout << ans[i] << " "; cout << "\n";
    return 0;
}
