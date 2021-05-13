#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
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
        cin >> n;
        int a[n];
        for(i=0; i<n; i++)
        {
            cin >> a[i];
        }
        string ans = "";
        for(i=0; i<n; i++)
        {
            j = a[i];
            k = 1;
            while(a[i+1]-j==1 && i<n-1)
            {
                i++;
                k++;
                j++;
            }
            //cout << i << " " << k << "\n";
            if(k>2)
            {
                ans += to_string(a[i-k+1]) + "..." + to_string(a[i]) + ",";
            }
            else if(k==1)
                ans += to_string(a[i]) + ",";
            else if(k==2)
                ans += to_string(a[i-1]) + "," + to_string(a[i]) + ",";
        }
        for(i=0; i<ans.size()-1; i++)
        {
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}
