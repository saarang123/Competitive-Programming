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
set<int> graph[N];
vi order;
int par[N], pos[N], dp[N];

int dfs(int v, int p)
{
    order.pb(v);
    pos[v] = order.size()-1;
    setitr it;
    dp[v] = 1;
    for(it=graph[v].begin(); it!=graph[v].end(); it++)
    {
        if(*it==p) continue;
        dfs(*it, v);
        dp[v] += dp[*it];
    }
    return dp[v];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> t;
    REP(i,2,n)
    {
        cin >> j;
        graph[j].insert(i);
    }
    dfs(1,-1);
    while(t--)
    {
        cin >> j >> k;
        if(k>dp[j])
        {
            cout << -1 << "\n";
            continue;
        }
        cout << order[pos[j]+k-1] << "\n";
    }
    return 0;
}
