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
    ifstream fin("homework.in");
    ofstream fout("homework.out");

    int i,j,n,t;
    fin >> n;
    int small[n], a[n];
    double sum = 0.0;
    vector<int> ans;
    for(i=0; i<n; i++)
    {
         fin >> a[i];
         small[i] = a[i];
    }
    small[n-1] = a[n-1];

    //cout << a[0] << " ";
    for(i=1; i<n; i++)
    {
        a[i]+=a[i-1];
        //cout << a[i] << " ";
    }
    //cout << "\n";
    //cout << small[n-1] << " ";

    for(i=n-2; i>=0; i--)
    {
        if(small[i]>=small[i+1])
            small[i] = small[i+1];
        //cout << small[i] << " ";
    }
    //cout << "\n";

    double pres = -INF;
    for(i=1; i<=n-2; i++)
    {
        sum = a[n-1] - a[i-1] - small[i];
        //cout << sum << " ";
        sum = sum*1.00/(n-i-1.0);
        //cout << sum << "\n";
        if(sum>pres)
        {
            ans = {};
            ans.pb(i);
            pres = sum;
        }
        else if(sum==pres)
            ans.pb(i);
        //cout << pres << "\n";
    }
    //cout << "\n";
    for(i=0; i<ans.size(); i++)
        fout << ans[i] << "\n";
    return 0;
}
