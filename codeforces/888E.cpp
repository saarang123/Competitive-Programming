#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
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

//-------------------------------------------------Template Ends------------------------------------------------------/

#define int long long
vi a(40),l,r;

vi calc(vi x, int c, int n, int m)
{
    for(int mask=0; mask < (1LL<<n); mask++)
    {
        int sum = 0;
        REP(i,0,n-1)
        {
            if(mask & (1LL<<i))
                sum += a[i+c];
            sum = sum%m;
        }
        x.pb(sum);
    }
    return x;
}

int solve(vi a, int n, int m)
{
    l=calc(l,0,n/2,m);
    r=calc(r,n/2,n-n/2,m);
    sort(all(l));
    sort(all(r));
    int ans = -1;
    //REP(i,0,l.size()-1) cout << l[i] << " "; cout << "\n";
    //REP(i,0,r.size()-1) cout << r[i] << " "; cout << "\n";

    REP(i,0,l.size()-1)
    {
        int ind = lower_bound(all(r), m-l[i]) - r.begin();
        if(ind==0) continue;
        ind--;
        //cout << l[i] << " " << r[ind] << "\n";
        ans = max(ans,l[i]+r[ind]);
    }

    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> m;
    RE(i,n) {cin >> a[i-1]; }
    cout << solve(a,n,m) << "\n";
    return 0;
}
