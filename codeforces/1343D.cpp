#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
//#define int long long
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

#define setitr set <int, greater <int> > :: iterator
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
    int a[n+3],xs[2*k+2]={0},ks[2*k+1]={0}, kl[2*k+1]={0};
    RE(i,n) cin >> a[i];
    RE(i,n/2)
    {
        j = max(a[i], a[n-i+1]);
        m = min(a[i], a[n-i+1]);
        kl[j]++;
        ks[m]++;
        xs[a[i]+a[n-i+1]]++;
    }
    ks[0] = 0;
    RE(i,2*k+1)
    {
        ks[i] += ks[i-1];
        kl[i] += kl[i-1];
    }
    //RE(i,2*k) cout << kl[i] << " "; cout << "kl\n";
    //RE(i,2*k) cout << ks[i] << " "; cout << "ks\n";
    int ans = INF;
    RE(i,2*k)
    {
        int p = (kl[max(0,i-k-1)] + ks[2*k]-ks[i-1]);
        int cnt = 2*p + (n/2-p) - xs[i];
        ans = min(ans,cnt);
        //cout << cnt <<  " ";
    }
    //cout << "\n";
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
