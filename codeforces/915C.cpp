#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;

void soln(vector<ll> v1, vector<ll> v2)
{
    int s1 = v2.size();
    //cout << s1 << "\n";
    for(int i=0; i<s1; i++)
    {

        vector<ll>::iterator j = v1.begin();
        while(j!=v1.end() && *j>v2[i])
        {
            ++j;
        }
        int pres = *j;
        cout << pres<<"\n";
        if(j!=v1.end()) v1.erase(j);
        if(pres<v2[i])
        {
            for(int k = 0; k<v1.size(); k++)
            {
                cout << v1[k];
            }
            break;
        }
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ll n,i,j,a,b;
    cin >> a >> b;
    ll a1=a, b1=b;
    //cout << a1 << " " << b1;
    vector<ll> s1;
    while(a1>0)
    {
        s1.pb(a1%10);
        a1/=10;
    }
    //cout << "\n";
    vector< ll> s2(s1.size());
    for(i=s1.size()-1; i>0; i--)
    {
        s2[i] = b1%10;
        b1/=10;
        //cout << "G" << " ";
    }
    s2[0] = b1;
    sort(s1.begin(), s1.end(), greater<ll>());

    for(i=0; i<s1.size(); i++)
        cout << s1[i] << " ";
    cout << "\n";
    for(i=0; i<s2.size(); i++)
        cout << s2[i] << " ";
    cout << "\n";

    soln(s1, s2);
    return 0;
}
