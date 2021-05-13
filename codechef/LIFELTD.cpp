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
        char s[3][3];
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                cin >> s[i][j];
            }
        }
        int ans = 0;
        for(i=0; i<2; i++)
        {
            for(j=0; j<2; j++)
            {
                if(s[i][j]==s[i+1][j] && s[i][j]==s[i+1][j+1] && s[i][j]=='l')
                {
                    ans = 1;
                    break;
                }
            }
        }
        if(ans)
            cout << "yes" << "\n";
        else
            cout << "no\n";
    }
    return 0;
}
