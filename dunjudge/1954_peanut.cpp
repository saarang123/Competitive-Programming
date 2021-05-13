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

const int N = 3e5+5;
vpll graph[N];
ll ds[N];

void dijkstra(ll src, ll n)
{
    REP(i,0,n) ds[i]=INF;
    priority_queue<pll, vector<pll>, greater<pll> > pq;

    pq.push(mp(0,src));
    ds[src] = 0;

    while(!pq.empty())
    {
        ll u = pq.top().ss;
        pq.pop();
        for(pii p: graph[u])
        {
            ll v = p.f, w = p.ss;
            if(ds[v]>ds[u]+w)
            {
                ds[v] = ds[u]+w;
                pq.push(mp(ds[v],v));
            }
        }
    }
}


int main()
{
	ll n,i,j,k,m,t,w,q;
	cin >> n >> m >> w;
	RE(i,m)
	{
	    cin >> i >> j >> k;
	    i++,j++;
	    graph[i-1].pb(mp(j,k));
	}
	RE(i,n)
	{
	    graph[i].pb(mp(i-1,w));
	}
	dijkstra(0,n);
	cout << ds[n] << "\n";
	return 0;
}

