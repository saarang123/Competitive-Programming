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
        cin >> n;
        j=1;
        int q[n], ans;
        vector<int> v;
        bool in[n+1] = {false};

        for(i=0; i<n; i++)
            cin >> q[i];
        ans = q[0];
        v.pb(ans);
        //cout << q[0] << " ";
        in[q[0]] = true;
        for(i=1; i<n; i++)
        {
            if(q[i]>ans)
            {
                //cout << q[i] << " ";
                v.pb(q[i]);
                ans = q[i];
                in[q[i]] = true;
            }
            else
            {
                while(in[j])
                    j++;
                if(j>q[i])
                    break;
                //cout << j << " ";
                v.pb(j);
                in[j] = true;
            }
        }
        /*
        cout << "\n";
        for(i=1; i<=n; i++)
            cout << in[i] << " ";
        */
        if(v.size()==n)
        {
            for(i=0; i<n; i++)
                cout << v[i] << " ";
        }
        else
            cout << -1;

        cout << "\n";
    }
    return 0;
}
