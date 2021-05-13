#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;

vector<string> ch[100];

int common(int i, int j)
{
    vector<string> &v1 = ch[i], &v2 = ch[j];
    int c = 1;
    string s1,s2;
    for(int p = 0; p<v1.size(); p++)
    {
        s1 = v1[p];
        for(int q = 0; q<v2.size(); q++)
        {
            s2 = v2[q];
            if(s1==s2)
            {
                c++;
                cout << s1 << " " << s2 << "\n";
            }
        }
    }
    return c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ifstream fin("guess.in");
    ofstream fout("guess.out");
    int n,k, i, j;
    string s;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> s >> k;
        for(j=0; j<k; j++)
            cin >> s;
            ch[i].pb(s);
    }
    for(i=0; i<n; i++)
    {
        vector<string> &v = ch[i];
        for(j=0 ;j<ch[i].size(); j++)
        {
            cout << v[j];
        }
        cout << "\n";
    }
    int l = -1;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            l = max(l, common(i,j));
            cout << i << " " << j << " " << common(i,j) << "\n";
        }
    }
    cout << l << "\n";
    return 0;
}
