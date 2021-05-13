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

int parent[200005],len[200005];

void make_set(int i)
{
    parent[i] = i;
    len[i] = 1;
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
        len[a] += len[b];
    }
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
        cin >> n;
        int a[n+1];
        for(i=1; i<=n; i++)
        {
            cin >> a[i];
            make_set(i);
        }
        for(i=1; i<=n; i++)
        {
            union_set(i, a[i]);
        }
        for(i=1; i<=n;i++)
        {
            cout << len[find_set(i)] << " ";
        }
        cout << "\n";
    }
    return 0;
}
