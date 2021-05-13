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
pair<ll,ll> ans = mp(1,1);

ll mas(ll a[], int j, int size)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = j; i <= size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            ans.ss++;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            ans.f = i+1;
            ans.ss = i;
        }
    }
    return max_so_far;
}

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
        ll a[n+1],sum=0;
        for(i=1; i<=n; i++)
        {
            cin >> a[i];
            sum+=a[i];
        }
        ll ret = max(mas(a,1,n-1), mas(a,2,n));
        //cout << sum << " " << ret << "\n";
        if(ret>=sum)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}
