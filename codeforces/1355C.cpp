#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+3;
long long ok[N];
void solve_case()
{
    // :pray: :fishy: :orz:
    int a,b,c,d,i,j;
    cin >> a >> b >> c >> d;
    for(i=a; i<=b; i++)
    {
        ok[i+b]++;
        ok[i+c+1]--;
    }
    for(i=1; i<N; i++) ok[i] += ok[i-1];
    for(i=1; i<N; i++) ok[i] += ok[i-1];
    long long ans = 0;
    for(i=c; i<=d; i++) ans += ok[N-2] - ok[i];
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
