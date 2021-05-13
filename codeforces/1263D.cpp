#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define sec second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
typedef long long ll;
int par[30], fr[200005][30], vis[30];

void make()
{
    RE(i,26) par[i] = i;
}

int fin(int v)
{
    if(par[v]==v) return v;
    return par[v] = fin(par[v]);
}

void join(int a, int b)
{
    a = fin(a); b = fin(b);
    if(a!=b)
    {
        par[a] = b;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k;
    cin >> n;
    string s;
    make();
    RE(i,n)
    {
        cin >> s;
        REP(j,0,s.size()-1)
        {
            fr[i][s[j]-'a'+1] = 1;
            vis[s[j]-'a'+1] = 1;
        }
        vector<int> v;
        RE(j,26) if(fr[i][j]) v.pb(j);
        REP(j,0,v.size()-1)
        {
            REP(k,j+1,v.size()-1)
            {
                join(v[j],v[k]);
            }
        }
    }
    set<int> cnt;
    RE(i,26) if(vis[i]) cnt.insert(fin(i));
    cout << cnt.size() << "\n";
}
