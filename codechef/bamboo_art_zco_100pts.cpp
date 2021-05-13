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
    cin >> n;
    int a[n];
    for(i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    vector<map<int, int> > diff(n);
    for(i=n-2; i>=0; i--)
    {
        for(j=i+1; j<n; j++)
        {
            k = a[j]-a[i];
            if(diff[j].count(k))
            {
                diff[i][k] = diff[j][k]+1;
            }
            else
                diff[i][k] = 2;
        }
    }
    map<int, int>::iterator itr;
    int ans = -1;
    for(i=0; i<n; i++)
    {
        for(itr=diff[i].begin(); itr!=diff[i].end(); itr++)
        {
            ans = max(ans, itr -> s);
        }
    }
    cout << ans << "\n";
    return 0;
}
