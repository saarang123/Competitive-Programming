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

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

//-------------------------------------------------Template Ends------------------------------------------------------/

void solve_case()
{
    int a,b,c,d, i, j, k;
    cin >> a >> b >> c >> d;
    if(a+b+c+d==0)
    {
        cout << 0 << "\n";
        return;
    }
    int z=-1, o=-1;
    for(i=1; i<=1e5; i++)
    {
        if(i*(i-1) == 2*a && z==-1) z = i;
        if(i*(i-1)==2*d && o==-1) o = i;
    }
    if(z==-1 || o==-1)
    {
        cout << "Impossible" << "\n";
        return;
    }
    if(a==0 || d==0)
    {
        if(b+c==0) {
        if(b+c==0 && z==1) z=0;
        if(b+c==0 && o==1) o=0;
        string ans = string(z, '0') + string(o, '1');
        cout << ans << "\n";
        return;
        }
    }
    if(z*o != (b+c))
    {
        cout << "Impossible" << "\n";
        return;
    }
    //cout << z << " " << o << "\n";
    string ans = "";
    i = 0;
    while(i++<z) ans += "0";
    i = 0;
    while(i++<o) ans += "0";
    for(i=0; i<ans.size(); i++)
    {
        if(z==0 || b<o)
        {
            ans[i] = '1';
            c -= z;
            o--;
        }
        else
        {
            b -= o;
            z--;
        }
    }
    cout << ans << -"\n";
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
