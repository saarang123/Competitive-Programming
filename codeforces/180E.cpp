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

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 2e5+5;
int a[N];
vi g[N];
void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n >> m >> k;
    RE(i,n)
    {
        cin >> a[i];
        g[a[i]].pb(i);
    }
    int m1 = 1, m2 = n;
    bool pos = false;
    while(m1!=m2)
    {
        int mid = (m1+m2+1)/2;
        pos = false;
        //cout << "bs vals: " << m1 << " "  << mid << " " << m2 << ": \n";
        RE(i,m)
        {
            int sz = g[i].size();
            if(sz==0) continue;
            for(j=sz-1; j>=0; j--)
            {
                if(j-mid+1<0) continue;
                if(g[i][j] - g[i][j-mid+1] - (mid-1) <= k)
                {
                    pos = true;
                    break;
                }
            }
            if(pos) break;
        }
        if(pos) m1 = mid;
        else m2 = mid-1;
    }
    cout << m1 << "\n";
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
