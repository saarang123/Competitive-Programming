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

vector<int> parent, len;

void make_set(int v)
{
    parent[v] = v;
    len[v] = v;
}

int find_set(int v)
{
    if(v==parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(len[a]<len[b])
            swap(a,b);
        parent[b] = a;
        len[a]+=len[b];
    }
}

struct Edge
{
    int v,u,weight;
    bool operator<(Edge const& other)
    {
        return weight<other.weight;
    }
};

int mst(vector<Edge> graph)
{
    sort(graph.begin(), graph.end());
    graph[0].weight = 0;       //first marking is 0 value
    int cost = 0;
    for(int i=0; i<graph.size(); i++)
    {
        Edge ed = graph[i];
        if(find_set(ed.v)!=find_set(ed.u))
        {
            cost = max(cost, ed.weight);
            union_set(ed.u, ed.v);
        }
        //cout << ed.v << " " << ed.u << " " << ed.weight << "\n";
    }
    return cost;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,m,t,k;
    cin >> n >> m;
    parent.resize(n);
    len.resize(n);
    for(i=0; i<n; i++)
        make_set(i);
    string s[n];
    for(i=0; i<n; i++)
        cin >> s[i];
    vector<Edge> graph;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(i==j) continue;
            int w = 0;
            for(k=0; k<m; k++)
            {
                w = max(w, abs(s[i][k]-s[j][k]));
            }
            Edge ed{i,j,w};
            graph.pb(ed);
        }
    }
    int ans = mst(graph);
    cout << ans << "\n";
    return 0;
}
