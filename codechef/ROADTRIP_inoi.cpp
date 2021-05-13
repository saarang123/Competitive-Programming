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
vector<vector<int> > graph(1000003);
int vis[1000003] = {0}, a[1000003];


/*
    Idea is to use DFS to find all the connected components of the graph.
    We find the total number of museums in each of these connected components and
    sort them. Choose the largest one for Lavanya, smallest for Nikhil,
    2nd largest for Lavanya again, 2nd smallest for Nikhil and so one
    until K months are over. If no. of connected components < K,
    we output -1.
*/

int dfs(int src)
{
    if(vis[src]) return 0;
    vis[src] = 1;
    int ans = a[src];
    //cout << src << " ";
    for(int i=0; i<graph[src].size(); i++)
    {
        if(!vis[graph[src][i]])
            ans+=dfs(graph[src][i]);
    }
    //cout << "\n";
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,u,v,t,k,m;
    cin >> t;
    while(t--)
    {
        for(i=0; i<n; i++)
        {
            graph[i].clear();
            vis[i] = 0;
        }
        cin >> n >> m >> k;
        for(i=0; i<m; i++)
        {
            cin >> u >> v;
            u--,v--;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        for(i=0; i<n; i++)
        {
            cin >> a[i];
            vis[i] = 0;

        }
        vector<int> ans;
        for(i=0; i<n; i++)
        {
            if(!vis[i])
            {
                int jo = dfs(i);
                ans.pb(jo);
                //cout << jo << "\n";
            }
        }
        sort(ans.begin(), ans.end(), greater<int>());
        if(ans.size()<k)
            cout << "-1\n";
        else
        {
            ll sol = 0;
            int l = 0, r = ans.size()-1;
            for(i=0; i<k; i++)
            {
                if(i%2==0)
                {
                    sol+=ans[l];
                    l++;
                }
                else
                {
                    sol+=ans[r];
                    r--;
                }
            }
            cout << sol << "\n";
        }
    }
    return 0;
}
