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

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int N = 35;
ll a[N], d[105];

ll fork(ll n, ll k)
{
    ll pres = 1, p=0;
    while(pres<=n)
    {
        pres*=k;
        p++;
    }
    return p-1;
}

void split(ll n, ll k)
{
    ll p = fork(n,k);
    ll pres = pow(k,p);
    while(n>=k)
    {
        while(n>=pres) {n = n-pres; d[p]++; }
        p--;
        pres = pres/k;
    }
    d[0]+=n;
    //REP(i,0,40) cout << d[i] << " "; cout << "\n";
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
        cin >> n >> k;
        REP(i,0,100) d[i] = 0;
        RE(i,n) cin >> a[i];
        RE(i,n) {split(a[i],k);}
        bool pos = true;
        REP(i,0,100)
        {
            if(d[i]>1) pos = false;
        }
        if(pos) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}

