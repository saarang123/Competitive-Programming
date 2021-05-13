#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

const int N = 2e5+3;
vector<int> g[N];
int par[N], dt[N];

void dfs(int v, int p, int d)
{
    dt[v] = d;
    par[v] = p;
    for(int u: g[v])
    {
        if(u==p) continue;
        dfs(u,v,d+1);
    }
}

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n;
    for(i=0; i<n-1; i++)
    {
        cin >> j >> k;
        g[j].push_back(k);
        g[k].push_back(j);
    }
    dfs(1,-1,0);
    set<pair<int, int> > far;
    for(i=1; i<=n; i++)
    {
        if(dt[i]>2) far.insert(make_pair(dt[i], i));
    }
    int ans = 0;
    while(!far.empty())
    {
        int v = par[(*far.rbegin()).second];
        ans++;
        for(int u: g[v])
        {
            far.erase(make_pair(dt[u], u));
        }
        far.erase(make_pair(dt[v], v));
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
