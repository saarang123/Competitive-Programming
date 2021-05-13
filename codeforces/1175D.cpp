#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// ----------------------------------------Defines and Template-------------------------------------//
#define int long long
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

#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e9;

//-------------------------------------------------Template Ends------------------------------------------------------/

void solve_case()
{
    //Answer for the K partitions can be represented in terms of their suffix sum ka differences.
    //Expanding we can see its just the k-1 largest suffix sums that hv to be chosen.
    //1st element is has to be included as 1st one.
    int n,i,j,t,k,m;
    cin >> n >> k;
    int a[n], pref[n];
    RE(i,n) cin >> a[i-1];
    reverse(a,a+n);
    pref[0] = a[0];
    RE(i,n-1) pref[i] = pref[i-1] + a[i];

    //RE(i,n) cout << pref[i-1] << " "; cout << "\n";

    int ans = pref[n-1];
    sort(pref,pref+n-1, greater<int>());
    RE(i,k-1)
    {
        ans += pref[i-1];
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve_case();
    }
    return 0;
}
