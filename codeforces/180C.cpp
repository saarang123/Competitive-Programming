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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    string s;
    cin >> s;
    n = s.size();
    int cnt[100005];
    cnt[0] = 0;
    REP(i,0,n-1)
    {
        cnt[i+1] = cnt[i];
        if(s[i]>='A' && s[i]<='Z') cnt[i+1]++;
    }
    int ans = n;
    for(i=0; i<=n; i++)
    {
        int low = i-cnt[i];
        int up = cnt[n]-cnt[i];
        ans = min(ans, low+up);
    }
    cout << ans << "\n";
    return 0;
}
