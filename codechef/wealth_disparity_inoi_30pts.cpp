#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
vector<set<int> > graph(100005);
int n;


int bfs(int src, int a[])
{
    int ans = -INF;
    bool vis[n];
    for(int i=0; i<n; i++)
        vis[i] = false;
    queue<int> q;
    vis[src] = 1;
    q.push(src);
    while(!q.empty())
    {
        int ver = q.front(); q.pop();
        for(int adj : graph[ver])
        {
            if(!vis[adj])
            {
                ans = max(a[src]-a[adj], ans);
                q.push(adj);
                vis[adj] = 1;
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,j,t,k;
    cin >> n;
    int a[n], p;
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(i=0; i<n; i++)
    {
        cin >> p;
        p--;
        if(p>-1)
            graph[p].insert(i);
    }
    /*
    for(i=0; i<n; i++)
    {
        //set<int, greater<int> > ::iterator itr;
        cout << i << ": ";
        for(auto itr=graph[i].begin(); itr!=graph[i].end(); itr++)
            cout << *itr << " ";
        cout << "\n";
    }
    */

    int res = -INF;
    for(i=0; i<n; i++)
    {
        res = max(res, bfs(i,a));
    }
    cout << res << "\n";

    return 0;
}
