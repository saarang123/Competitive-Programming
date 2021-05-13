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

set<int> graph[28];
int vis[28] = {0};
string s;
string alpha = "abcdefghijklmnopqrstuvwxyz";
bool pos;


void print_graph()
{
    REP(i,0,25)
    {
        cout << i << ": ";
        for(auto j: graph[i])
        {
            cout << j << ", ";
        }
        cout << "\n";
    }
}

void dfs(int v, int par)
{
    if(vis[v])
    {
        pos = false;
        return;
    }
    vis[v] = 1;
    for(auto u: graph[v])
    {
        if(u==par) continue;
        dfs(u,v);
    }
}

string dfs2(int v)
{
    if(v==-1) return "";
    if(vis[v]) return "";
    vis[v] = 1;
    string pres(1,alpha[v]);
    for(auto u: graph[v])
    {
        pres += dfs2(u);
    }
    return pres;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> t;
    while(t--)
    {
        REP(i,0,26){ graph[i].clear(); vis[i] = 0; }
        cin >> s;
        n = s.size();
        REP(i,0,n-2)
        {
            graph[s[i]-'a'].insert(s[i+1]-'a');
            graph[s[i+1]-'a'].insert(s[i]-'a');
        }
        //print_graph();

        pos = true;
        REP(i,0,25)
        {
            if(graph[i].size()>2) pos = false;
        }
        if(!pos)
        {
            cout << "NO\n";
            continue;
        }

        REP(i,0,25)
        {
            if(!vis[i]) dfs(i,-1);
            if(!pos) break;
        }
        if(!pos)
        {
            cout << "NO\n";
            continue;
        }

        REP(i,0,26) vis[i] = 0;
        string ans = "";
        int start = -1;
        REP(i,0,25)
        {
            if(graph[i].size()==1) start = i;
        }
        ans+=dfs2(start);
        REP(i,0,25)
        {
            if(graph[i].empty())
                ans += alpha[i];
        }
        cout << "YES\n";
        cout << ans << "\n";

    }
    return 0;
}
