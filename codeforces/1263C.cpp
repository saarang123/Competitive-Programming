#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define mapitr map<int, int> :: iterator
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
        set<int> s;
        int sq = sqrt(n)+1;
        for(i=1; i<=sq; i++)
            s.insert(n/i);
        for(i=0; i<sq; i++)
            s.insert(i);

        cout << s.size() << "\n";
        setitr itr;
        for(itr=s.begin(); itr!=s.end(); itr++)
            cout << *itr << " ";
        cout << "\n";
    }
    return 0;
}
