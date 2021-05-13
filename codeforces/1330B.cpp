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

const int mod = 1e9+7;
const int INF = 1e9;

//-------------------------------------------------Template Ends------------------------------------------------------/

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n;
    int a[n+3], use[n+3];
    RE(i,n) use[i] =0;
    RE(i,n) { cin >> a[i]; use[a[i]]++; }

    int m1[n+2], m2[n+3];
    RE(i,n) { m1[i]=a[i];m2[i] = a[i];}
    m1[1] = a[1];
    REP(i,2,n) m1[i] = max(m1[i], m1[i-1]);
    m2[n] = a[n];
    REB(i,n-1,1) m2[i] = max(m2[i], m2[i+1]);

    int pos = 0;
    i = 1;
    while(use[i]==2)
    {
        pos = i;
        i++;
    }

    REP(i,pos+1,m1[n])
    {
        if(use[i]!=1)
        {
            cout << "0\n";
            return;
        }
    }

    int sz1[n+3], sz2[n+3];
    sz1[1] = 1, sz2[n] = 1;
    set<int> s1,s2;
    RE(i,n)
    {
        s1.insert(a[i]);
        sz1[i] = s1.size();
    }
    FO(i,n)
    {
        s2.insert(a[i]);
        sz2[i] = s2.size();
    }
    //RE(i,n) cout << m1[i] << " "; cout << "\n";
    //RE(i,n) cout << m2[i] << " "; cout << "\n";

    vpii ans;
    RE(i,n-1)
    {
        if(m1[i]==i && sz1[i]==i && m2[i+1]==n-i && sz2[i+1]==n-i)
        {
            ans.pb(mp(i,n-i));
        }
    }

    cout << ans.size() << "\n";
    for(pii p: ans) cout << p.f << " " << p.ss << "\n";
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
