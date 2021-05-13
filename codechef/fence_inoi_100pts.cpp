#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
typedef long long ll;
typedef pair<int, int> pii;
set<pii> graph;
map<pii, int> vis;

int dfs(int i, int j)
{
    pii p = mp(i,j);
    if(!graph.count(p)) return 0;
    if(vis[p]) return 0;
    vis[p] = 1;
    int ans = 4 - graph.count(mp(i+1,j)) - graph.count(mp(i-1,j)) - graph.count(mp(i,j+1)) - graph.count(mp(i,j-1));
    //cout << i << " " << j << " " << ans << "\n";
    return ans + dfs(i+1,j) + dfs(i-1,j) + dfs(i,j-1) + dfs(i,j+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,r,c;
    cin >> r >> c >> n;
    for(i=0; i<n; i++)
    {
        cin >> j >> k;
        pii p = mp(j,k);
        vis[p] = 0;
        graph.insert(p);
    }
    map<pii, int>:: iterator itr;
    int ans = -1;
    for(itr = vis.begin(); itr!=vis.end(); itr++)
    {
        if(itr->s) continue;
        ans = max(ans, dfs(itr->f.f, itr->f.s));
    }
    cout << ans << "\n";
    return 0;
}
