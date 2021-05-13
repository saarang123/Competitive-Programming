#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
#define int long long
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

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b)/gcd(a, b)

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#define trav(i,a) for(auto i: a)
#define FOR(i,n) for(int i=0; i<n; i++)
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n >> k;
    int a[n+2];
    RE(i,n) cin >> a[i];
    sort(a+1,a+n+1);
    k = k*8;
    m = k/n;
    if(m>=20)
    {
        cout << 0 << "\n";
        return;
    }
    m = (1LL<<m);
    map<int, pii> cnt;
    RE(i,n)
    {
        if(cnt.find(a[i])!=cnt.end()) cnt[a[i]] = mp(min(cnt[a[i]].f,i), max(cnt[a[i]].ss, i));
        else cnt[a[i]] = mp(i,i);
    }
    set<int> s;
    RE(i,n) s.insert(a[i]);
    vi b; b.pb(0);
    for(int u: s) b.pb(u);
    int ans = INF;
    t = b.size()-1;
    for(i=1; i<=t; i++)
    {
        int cur = n-cnt[b[min(i+m-1,t)]].ss + cnt[b[i]].f-1;
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
