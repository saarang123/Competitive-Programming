#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int, int> pii;

vector<int> graph[100005];
int c[100005], vis[100005];
set<int> s;

void dfs(int src)
{
    if(vis[src]) return ;
    vis[src] = 1;
    //cout << "dfs: " << src << "\n";
    if(c[src])
    {
        int flag = 1;
        for(int i=0; i<graph[src].size(); i++)
        {
            if(c[graph[src][i]]==0) flag = 0;
            //cout << "respect: " << src << " " << flag << "\n";
        }
        if(flag)
        {
            s.insert(src);
            //cout << "delete: " << src << "\n";
        }
    }
    for(int i=0; i<graph[src].size(); i++)
    {
        dfs(graph[src][i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> j >> c[i];
        if(j==-1)
        {
            m = i;
            continue;
        }
        graph[j].pb(i);
    }
    dfs(m);
    setitr it;
    if(s.empty())
        cout << "-1\n";
    else
    {
        for(it=s.begin(); it!=s.end(); it++)
            cout << *it << " ";
        cout << "\n";
    }
    return 0;
}
