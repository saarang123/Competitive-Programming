#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD ((long long)1000000007)
#define INF 1000000000
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ll n,i,j=0,t=0,k=0;
    ll fib[100003];
    fib[0] = 1;
    fib[1] = 1;
    for(i=2; i<100001; i++)
        fib[i] = (fib[i-1]+fib[i-2])%MOD;
    string s;
    cin >> s;
    ll ans = 1;
    n = s.size();
    for(i=0; i<n; i++)
    {
        if(s[i]=='m' || s[i]=='w')
        {
            cout << "0\n";
            return 0;
        }
    }
    for(i=0,j=0; i<n,j<n; i=j)
    {
        while(s[i]==s[j] && j<n)
            j++;
        if(s[i]=='u' || s[i]=='n')
        {
            ans = ((ll)ans*fib[j-i])%MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}
