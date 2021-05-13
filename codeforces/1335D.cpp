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

void solve_case()
{
    int n,i,j,t,k,m;
    int sud[10][10];
    RE(i,9)
    {
        string s;
        cin >> s;
        RE(j,9)
        {
            sud[i][j] = s[j-1]-'0';
        }
    }
    j = 1;
    RE(i,3)
    {
        sud[i][j] = (sud[i][j]+1);
        if(sud[i][j]==10) sud[i][j] = 1;
        j+=3;
    }
    j = 2;
    for(i=4; i<=6; i++)
    {
        sud[i][j] = (sud[i][j]+1);
        if(sud[i][j]==10) sud[i][j] = 1;
        j+=3;
    }
    j = 3;
    for(i=7; i<=9; i++)
    {
        sud[i][j] = (sud[i][j]+1);
        if(sud[i][j]==10) sud[i][j] = 1;
        j+=3;
    }
    RE(i,9)
    {
        RE(j,9)
        {
            cout << sud[i][j];
        }
        cout << "\n";
    }
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
