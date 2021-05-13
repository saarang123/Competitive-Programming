#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
int n;
vector<vector<int> > graph(205);

int bfs(int src)
{
    bool vis[n];
    int ans = 1;
    for(int i=0; i<n; i++) vis[i]=false;
    vis[src] = true;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int p = q.front(); q.pop();
        for(int node: graph[p])
        {
            if(!vis[node])
            {
                q.push(node);
                vis[node] = true;
                //cout << node << " ";
                ans++;
            }
        }
    }
    return ans;
}

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    int i,j,x,y, p;
    fin >> n;
    vector<pair<int, int> > v(n);
    int pow[n];
    for(i=0; i<n; i++)
    {
        fin >> x >> y >> p;
        v[i] = {x,y};
        pow[i]=p;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            pair<int, int> p = v[i], p2 = v[j];
            if(dist(p.f, p.s, p2.f, p2.s)<=pow[i])
                graph[i].pb(j);
        }
    }
    int m = -1;
    for(i=0; i<n; i++)
    {
        m = max(m, bfs(i));
        //cout << bfs(i) << "\n";
    }
    fout << m << "\n";
    return 0;
}
