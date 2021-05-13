#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000
typedef long long ll;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ll i,j,n,t;
    cin >> n;
    ll a[n], s=0;
    for(i=0; i<n; i++)
    {
        cin >> a[i];
        s+=a[i];
    }
    sort(a, a+n, greater<ll>());
    ll s1=0, s2=0,l;
    if(n%2==0)
        l = n/2;
    else
        l = n/2+1;
    for(i=0; i<l;i++)
    {
        s1+=a[i];
    }
    s2 = s-s1;
    ll ans = (s1*s1)+(s2*s2);
    cout << ans << "\n";
    return 0;
}
