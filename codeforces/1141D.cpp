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

vi rt[26], lt[26], qn1, qn2, rem1,rem2, remqn1, remqn2;
void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n)
    {
        char c;
        cin >> c;
        if(c=='?') qn1.pb(i);
        else lt[c-'a'].pb(i);
    }
    RE(i,n)
    {
        char c;
        cin >> c;
        if(c=='?') qn2.pb(i);
        else rt[c-'a'].pb(i);
    }
    vpii cnt;

    REP(i,0,25)
    {
        vi::iterator it1=lt[i].begin(), it2=rt[i].begin();
        while(it1!=lt[i].end() && it2!=rt[i].end())
        {
            cnt.pb(mp(*it1,*it2));
            it1++; it2++;
        }
        while(it1!=lt[i].end())
        {
            rem1.pb(*it1);
            it1++;
        }
        while(it2!=rt[i].end())
        {
            rem2.pb(*it2);
            it2++;
        }
    }

    vi::iterator it1 = qn1.begin(), it2 = rem2.begin();
    while(it1!=qn1.end() && it2!=rem2.end())
    {
        cnt.pb(mp(*it1,*it2));
        it1++; it2++;
    }
    while(it1!=qn1.end())
    {
        remqn1.pb(*it1);
        it1++;
    }

    it1 = qn2.begin(); it2 = rem1.begin();
    while(it1!=qn2.end() && it2!=rem1.end())
    {
        cnt.pb(mp(*it2,*it1));
        it1++; it2++;
    }
    while(it1!=qn2.end())
    {
        remqn2.pb(*it1);
        it1++;
    }

    it1 = remqn1.begin(); it2=remqn2.begin();
    while(it1!=remqn1.end() && it2!=remqn2.end())
    {
        cnt.pb(mp(*it1,*it2));
        it1++; it2++;
    }

    cout << cnt.size() << "\n";
    vpii::iterator it = cnt.begin();
    while(it!=cnt.end())
    {
        cout << (*it).f << " " << (*it).ss << "\n";
        it++;
    }
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
