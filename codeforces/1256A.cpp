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
    int n,i,j,t,k, a, b, s;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> n >> s;
        if(s-(n*min(s/n, a)) <=b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
