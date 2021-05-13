#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,t,i,j;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> n >> s;
        int ans = n, ans2=0, c1, c2;
        for(i=0; i<n; i++)
        {
            if(s[i]=='1')
            {
                ans = max(ans, (i+1)*2);
                ans2++;
            }
            ans2++;
        }
        c1 = max(ans, ans2);
        //cout << max(ans, ans2) << "\n";
        ans = n; ans2=0;
        for(i=n-1; i>=0; i--)
        {
            if(s[i]=='1')
            {
                ans = max(ans, (n-i)*2);
                ans2++;
            }
            ans2++;
        }
        c2 = max(ans, ans2);
        cout << max(c1,c2) << "\n";
    }
    return 0;
}
