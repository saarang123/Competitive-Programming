#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k;
    cin >> t;
    while(t--)
    {
        int a[3];
        int ans;
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3, greater<int>());
        ans = a[2] + a[0]/2;
        cout << ans << "\n";
    }
    return 0;
}
