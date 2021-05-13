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
#define rip signed
#define kobe main()
#define bryant ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

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
#define FOR(i,n) for(int i=0; i<n; i++)
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 503;
int a[N], deg[N];
vi lf;
vpii rst,ans;
void pls_give_AC()
{
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n)
    {
        cin >> a[i];
        if(a[i]==1) lf.pb(i);
        else rst.pb(mp(a[i],i));
    }
    sort(all(rst));
    //RE(i,n) deg[i] = 0;
    if(!rst.size())
    {
        cout << "NO\n";
        return;
    }
    deg[rst[0].ss] = 0;
    for(i=1; i<rst.size(); i++)
    {
        ans.pb(mp(rst[i].ss, rst[i-1].ss));
        deg[rst[i].ss]++;
        deg[rst[i-1].ss]++;
    }
    int cnt = 0;
    FOR(j,lf.size())
    {
        int flag = 0;
        int v = rst.front().ss;
        if(deg[v]<a[v])
        {
            ans.pb(mp(v,lf[j]));
            deg[v]++;
            continue;
        }
        v = rst.back().ss;
        if(deg[v]<a[v])
        {
            ans.pb(mp(v,lf[j]));
            deg[v]++;
            continue;
        }
        RE(i,n)
        {
            if(a[i]==deg[i]) continue;
            if(a[i]==1) continue;
            ans.pb(mp(lf[j],i));
            deg[i]++;
            flag = 1;
            break;
        }
        if(!flag)
        {
            cout << "NO\n";
            return;
        }
    }
    j = 0;
    if(lf.size()>1) j = 2;
    else j = 1;
    if(!lf.size()) j = 0;
    int d = rst.size()-1+j;
    cout << "YES" << " " << d << "\n";
    cout << ans.size() << "\n";
    FOR(i,ans.size()) cout << ans[i].f << " " << ans[i].ss << "\n";
}

rip kobe
{
    bryant;
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        pls_give_AC();
    }
    return 0;
}
