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
const int INF = 2e18;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/


int val(int a, int b, int c)
{
    return ((a-b)*(a-b) + (b-c)*(b-c) + (c-a)*(c-a));
}


int best(vi a, vi b, vi c)
{
    int na = a.size(), nb = b.size(), nc = c.size();
    int ans = 2e18;
    FOR(i,na)
    {
        int snd = lower_bound(all(b), a[i]) - b.begin();
        if(snd==nb) snd--;
        int thrd = lower_bound(all(c), a[i]) - c.begin();
        if(thrd==nc) thrd--;
        for(int j=max(0LL,snd-10); j<=min(nb-1,snd+10); j++)
        {
            for(int k=max(0LL,thrd-10); k<=min(nc-1,thrd+10); k++)
                ans = min(ans, val(a[i], b[j], c[k]));
        }
    }
    return ans;
}

void solve_case()
{
    int na,nb,nc,i,j,t,k,m;
    cin >> na >> nb >> nc;
    vi a(na), b(nb), c(nc);
    FOR(i,na) cin >> a[i];
    FOR(i,nb) cin >> b[i];
    FOR(i,nc) cin >> c[i];
    sort(all(a)); sort(all(b)); sort(all(c));
    int ans = INF;
    ans = min(ans, best(a,b,c));
    ans = min(ans, best(a,c,b));
    ans = min(ans, best(b,a,c));
    ans = min(ans, best(b,c,a));
    ans = min(ans, best(c,a,b));
    ans = min(ans, best(c,b,a));
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int Testcases = 1;
    cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
