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
int parent[500005], size[500003];

void make_set(int i)
{
    parent[i] = i;
    size[i] = 1;
}

int find_set(int v)
{
    if(v==parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}
void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(size[a]<size[b])  swap(a,b);
        parent[b] = a;
        size[a]+=size[b];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> m;
    for(i=0; i<n; i++)
        make_set(i);
    for(i=0; i<m; i++)
    {
        cin >> k;
        int p = -1;
        for(j=0; j<k; j++)
        {
            cin >> t;
            t--;
            if(p!=-1)
                union_set(p, t);
            p = t;
        }
    }
    for(i=0; i<n; i++)
    {
        cout << size[find_set(i)] << " ";
    }
    cout << "\n";
    return 0;
}
