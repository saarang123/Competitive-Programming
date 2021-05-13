#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

//-------------------------------------------------Template Ends------------------------------------------------------/

const int mod = 1e9+7;
const int INF = 1e9;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> m;
    int a[n+5];
    RE(i,n) a[i-1] = -1;
    vpii st,nst;
    while(m--)
    {
        cin >> t >> i >> j;
        i--,j--;
        if(t)
            st.pb(mp(i,j));
        else
            nst.pb(mp(i,j));
    }
    for(pii p: st)
    {
        REP(j,p.f,p.ss-1)
        {
            a[j] = 0;
        }
    }
    for(pii p: nst)
    {
        bool pos = 0;
        REP(j,p.f,p.ss-1)
        {
            if(a[j]==-1)
            {
                pos = 1;
                break;
            }
        }
        if(!pos)
        {
            cout << "NO\n";
            return 0;
        }
    }
    //RE(i,n) cout << a[i-1] << " "; cout << "\n";
    cout << "YES\n";
    int no = n+1;
    cout << n+1 << " ";
    REP(i,0,n-2)
    {
        cout << no+a[i] << " ";
        no += a[i];
    }
    cout << "\n";
    return 0;
}
