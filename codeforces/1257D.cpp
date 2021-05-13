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
const int N = 2e5+5;

//-------------------------------------------------Template Ends------------------------------------------------------/

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n;
    int a[n];
    RE(i,n) cin >> a[i-1];
    cin >> m;
    vpii ps(m);
    vi p(m), s(m);
    RE(i,m) cin >> ps[i-1].ss >> ps[i-1].f;
    sort(all(ps));
    RE(i,m) p[i-1] = ps[i-1].ss, s[i-1] = ps[i-1].f;

    //RE(i,m) cout << p[i-1] << " "; cout << "\n";
    //RE(i,m) cout << s[i-1] << " "; cout << "\n";

    map<int,int> lmao;
    int tm = -1;
    REB(i,m-1,0)
    {
        tm = max(tm, p[i]);
        lmao[s[i]] = tm;
    }

    int ans = 0, maxi=-1;
    REP(i,0,n-1)
    {
        maxi =  a[i]; j=i;
        for(;j<n;j++)
        {
            maxi = max(maxi,a[j]);
            auto ind = lmao.lower_bound(j-i+1);
            //cout << maxi << " " << i << " " << j << " " << (*ind).f << "\n";
            if(ind==lmao.end() || ind->ss<maxi) break;
        }
        if(i==j)
        {
            cout << -1 << "\n";
            return;
        }
        else
        {
            ans++;
            i = j-1;
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int T = 1;
    cin >> T;
    while(T--)
    {
        solve_case();
    }
    return 0;
}
