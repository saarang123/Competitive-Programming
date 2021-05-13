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

set<ll> s;

int main()
{
    //use mod x array with current value needed.
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,t,k,n,j,x,m;
    cin >> t >> x;
    ll cnt[x];
    for(i=0; i<x; i++) cnt[i] = i;
    for(i=0; i<x; i++) s.insert(i);

    while(t--)
    {
        cin >> j;
        s.erase(cnt[j%x]);
        cnt[j%x] += x;
        s.insert(cnt[j%x]);
        cout << *s.begin() << "\n";
    }
    return 0;
}
