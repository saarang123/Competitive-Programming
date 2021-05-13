#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

int gcd(int a, int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
int lcm(int a, int b)
{
    int g = gcd(a,b);
    return (a*b)/g;
}

string s[23], t[23];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,q,k,m;
    cin >> n >> m;
    RE(i,n) cin >> s[i];
    RE(i,m) cin >> t[i];

    int lc = lcm(n,m);
    string comp[lc+1];
    int l = 1, r=1;
    for(i=1; i<=lc; i++,l++,r++)
    {
        if(l>n) l = 1;
        if(r>m) r = 1;
        comp[i] = s[l]+t[r];
    }
    comp[0] = comp[lc];
    /*
    RE(i,lc)
    {
        cout << comp[i] << "\n";
    }
    */

    cin >> q;
    RE(i,q)
    {
        cin >> j;
        int p = j%lc;
        if(p==0) p = lc;
        cout << comp[p] << "\n";
    }

    return 0;
}
