#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
int n;
vector<vector<int> > graph(305);

int bfs()
{
    int ans = 1;
    bool vis[n];
    for(int i=0; i<n; i++)
        vis[i] = false;
    queue<int> q;
    vis[0] = 1;
    q.push(0);
    while(!q.empty())
    {
        int src = q.front(); q.pop();
        for(int adj : graph[src])
        {
            if(!vis[adj])
            {
                ans++;
                q.push(adj);
                vis[adj] = 1;
            }
        }
    }
    return ans;
}
bool edge(set<int> a, set<int> b, int k)
{
    int c = 0;
    set<int, greater<int> >::iterator itr;
    for(itr = a.begin(); itr!=a.end(); itr++)
    {
        if(b.count(*itr))
            c++;
    }
    if(c>=k)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,j,t,k,p;
    cin >> n >> k;
    vector<set<int> > id(n);
    for(i=0; i<n; i++)
    {
        cin >> p;
        for(j=0; j<p; j++)
        {
            cin >> t;
            id[i].insert(t);
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(edge(id[i], id[j], k))
            {
                graph[i].pb(j);
                graph[j].pb(i);
            }
        }
    }
    /*
    for(i=0; i<n; i++)
    {
        cout << i << ": ";
        for(j=0; j<graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    */
    cout << bfs() << "\n";
    return 0;
}
