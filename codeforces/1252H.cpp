#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
#define int unsigned long long
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
//-------------------------------------------------Template Ends------------------------------------------------------//

int rmin(pii a)
{
    return min(a.f,a.ss);
}

int rmax(pii a)
{
    return max(a.f,a.ss);
}

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n;
    vpii a(n);
    FOR(i,n) cin >> a[i].f >> a[i].ss;
    FOR(i,n) if(a[i].f > a[i].ss) swap(a[i].f, a[i].ss);
    sort(all(a),greater<pii>());
    int ans = 0;
    FOR(i,n)
    {
        int temp = (a[i].f*a[i].ss);
        ans = max(ans, temp);
    }
    int ans2 = 0, mx=0;
    FOR(i,n)
    {
        ans2 = max(ans2, min(mx,a[i].ss)*a[i].f);
        mx = max(mx,a[i].ss);
    }
    if(2*ans2>=ans)
    {
        cout << ans2 << ".0\n";
        return;
    }
    if(ans&1) cout << ans/2 << ".5\n";
    else cout << ans/2 << ".0\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
