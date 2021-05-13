#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define double long double
#define f first
#define ss second
#define mp make_pair
#define pb push_back

#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int N = 30;
ll graph[N][N];
ll dist[N][N];

void floyd_warshall()
{
    int i,j,k;
    for (i = 0; i < 26; i++)
        for (j = 0; j < 26; j++)
        {
            dist[i][j] = graph[i][j];
        }


    for (k = 0; k < 26; k++)
    {
        for (i = 0; i < 26; i++)
        {
            for (j = 0; j < 26; j++)
            {
                if(dist[i][k]==1e17 || dist[k][j]==1e17) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ll n,i,j,t,k,m;
    cin >> n >> m;
    string s;
    cin >> s;
    REP(i,0,26)
    {
        REP(j,0,26)
        {
            graph[i][j] = 1e17;
            if(i==j) graph[i][j] = 0;
        }
    }
    while(m--)
    {
        char a,b;
        cin >> a >> b >> i;
        graph[a-'a'][b-'a'] = min(graph[a-'a'][b-'a'],i);
    }
    floyd_warshall();
    i = 0; j = n-1;
    ll ans = 0;
    while(i<j)
    {
        ll pres = 1e17;
        REP(k,0,25)
        {
            ll c1 = dist[s[i]-'a'][k], c2 = dist[s[j]-'a'][k];
            if(c1==1e17 || c2==1e17) continue;
            pres = min(pres, c1+c2 );
        }
        if(pres==1e17)
        {
            cout << "-1\n";
            return 0;
        }
        ans+=pres;
        i++;
        j--;
    }
    cout << ans << "\n";
    return 0;
}
