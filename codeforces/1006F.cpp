#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 21;
map<ll, ll> cnt[N][N];
ll a[N][N], ans;
int mid, n, m, tot;
ll k;

bool in(int x, int y)
{
    return (x<1 || y<1 || x>n || y>m);
}

void fix(int x, int y, ll c, int mv)
{
    c ^= a[x][y];
    if(in(x,y)) return;
    if(mv==mid) return void(cnt[x][y][c]++);
    mv++;
    fix(x+1, y, c, mv);
    fix(x, y+1, c, mv);
}

void pray(int x, int y, ll c, int mv)
{
    if(in(x,y)) return;
    if(mv==tot-mid) return void(ans += cnt[x][y][c ^ k]);
    c ^= a[x][y];
    mv++;
    pray(x-1, y, c, mv);
    pray(x, y-1, c, mv);
}

void solve_case()
{
    // :pray: :fishy: :orz:
    int i,j;
    cin >> n >> m >> k;
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) cin >> a[i][j];
    tot = n+m-2;
    if(tot==0)
        return void(cout << (a[1][1]==k) << '\n');
    mid = tot/2;
    fix(1, 1, 0, 0);
    pray(n, m, 0, 0);
    cout << ans << "\n";
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
