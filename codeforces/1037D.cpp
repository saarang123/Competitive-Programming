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

const int N = 2e5+5;
set<int> graph[N];
int vis[N]={0}, b[N];
queue<int> q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n-1)
    {
        cin >> j >> k;
        graph[j].insert(k);
        graph[k].insert(j);
    }
    RE(i,n) cin >> b[i];
    bool pos = true;
    q.push(1);
    i = 2;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        while(!graph[v].empty())
        {
            if(!graph[v].count(b[i]))  {pos = false; break; }
            else
            {
                graph[v].erase(b[i]);
                graph[b[i]].erase(v);
                q.push(b[i]);
                i++;
                //cout << v << " " << b[i] << "\n";
            }
        }
        if(!pos) break;
    }
    if(pos) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
