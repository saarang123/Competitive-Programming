#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
vector<set<int> > graph(1003);
vector<pair<int, int> > seg(1003);
vector<int> v(1003);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,k,s, t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0; i<n; i++)
        {
            cin >> j >> k >> s;
            seg[i] = mp(j,k);
            v[i] = s;
        }

        for(i=0; i<n;  i++)
        {
            for(j=i+1; j<n; j++)
            {
                pair<int,int> p1=seg[i], p2=seg[j];
                if(((p1.f<=p2.f && p1.s>=p2.f) || (p1.f <= p2.s && p2.f <= p1.s) || (p1.f<=p2.s && p1.s>=p2.s) || (p1.f>=p2.f && p1.s<=p2.s)) && v[i]==v[j])
                {
                    graph[i].insert(j);
                    graph[j].insert(i);
                }
            }
        }
        int c = 1;
        for(i=0; i<n; i++)
        {
            for(auto itr = graph[i].begin(); itr!=graph[i].end(); itr++)
            {
                //cout << i << " ";
                j = *itr;
                for(auto it = graph[j].begin(); it!=graph[j].end(); it++)
                {
                    //cout << j << " ";
                    int k = *it;
                    //cout << i << " " << j << " " << k << "\n";
                    if(graph[i].count(k))
                    {
                         c=0;
                         break;
                    }
                }
            }
        }
        if(c)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}
