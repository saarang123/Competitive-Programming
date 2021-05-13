#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> t;
    while(t--)
    {
        cin >> n;
        string x,a="1", b="1";
        j=0;
        cin >> x;
        RE(i,n-1)
        {
            if(x[i]-'0'==2)
            {
                if(j==0)
                {
                    a+="1";
                    b+="1";
                    j = 0;
                }
                else if(j==1)
                {
                    b+="2";
                    a+="0";
                }
            }
            else if(x[i]-'0'==1)
            {
                if(j==1)
                {
                    b+="1";
                    a+="0";
                }
                else
                {
                    a+="1";
                    b+="0";
                    j = 1;
                }
            }
            else if(x[i]-'0'==0)
            {
                a+="0";
                b+="0";
            }
        }
        cout << a << "\n" << b << "\n";
    }
    return 0;
}
