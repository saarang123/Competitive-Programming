#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
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
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n+1], m[101]={0};
        RE(i,n)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        k=0;
        RE(i,100)
        {
            k = max(k,m[i]);
        }
        cout << n-k << "\n";

    }
    return 0;
}
