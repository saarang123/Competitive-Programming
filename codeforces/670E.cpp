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

#define trav(i,a) for(auto i: a)
#define FOR(i,n) for(int i=0; i<n; i++)
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

string s;
const int N = 5e5+2;
int a[N], in[N], out[N];
void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n >> m >> k;
    cin >> s;
    j = 0;
    set<int> br;
    int mx = 0;
    FOR(i,n)
    {
        if(s[i]=='(')
        {
            a[i] = mx++;
            br.insert(mx-1);
            in[a[i]] = i;
        }
        else
        {
            a[i] = *(br.rbegin());
            br.erase(a[i]);
            out[a[i]] = i;
        }
    }
    //FOR(i,n) cout << a[i] << " "; cout << "\n";
    //FOR(i,m) cout << in[i] << " " << out[i] << "\n";
    set<int> st;
    FOR(i,n) st.insert(i);
    auto p = st.find(--k);

    while(m--)
    {
        char c;
        cin >> c;
        if(c=='R')
        {
            p++;
        }
        else if(c=='L')
        {
            p--;
        }
        else
        {
            int cnt = a[*p], l = *p;
            pii rng = mp(in[cnt], out[cnt]);
            auto smh = st.lower_bound(rng.f), q = st.lower_bound(rng.ss);
            if(smh==st.end()) continue;
            if(*smh>rng.ss) continue;
            for(i=*smh; i<=min(rng.ss,*q); i++)
            {
                st.erase(i);
            }
            auto it = st.lower_bound(l);
            if(it==st.end()) --it;
            p = it;
        }
    }
    for(auto u: st) cout << s[u]; cout << "\n";

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
