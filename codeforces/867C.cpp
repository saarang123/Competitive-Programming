#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define ss second
#define mp make_pair
#define all(a) a.begin(), a.end()
#define int long long

int fn(int n, int k)
{
    return n/k + ((n%k)>0);
}

void print_vec(vector<pair<pair<int, int>, pair<int, int> > > v)
{
    for(auto p: v)
    {
        cout << p.f.f << " " << p.f.ss << " " << p.ss.f << " " << p.ss.ss << "\n";
    }
}

signed main()
{
    int t,i,j,n,m,k;
    cin >> n >> k;
    vector<pair<pair<int,int>, pair<int,int> > > vec;
    for(i=0; i<n; i++)
    {
        int s,a,b;
        cin >> s >> a >> b;
        vec.pb(mp(mp(abs(a-b), s), mp(a,b)));
    }
    sort(all(vec));
    //print_vec(vec);
    int cnt1=0, cnt2=0, hap=0;
    for(i=0; i<n; i++)
    {
        int s = vec[i].f.ss, a = vec[i].ss.f, b = vec[i].ss.ss;
        if(a>b)
        {
            cnt1 += s;
            hap += (s*a);
        }
        else
        {
            cnt2 += s;
            hap += (s*b);
        }
    }
    //cout << "happiness " << hap << " cnt1: " << cnt1 << " cnt2: " << cnt2 << "\n";
    int need = fn(cnt1+cnt2,k), s1=fn(cnt1,k), s2=fn(cnt2,k);
    //cout << "need " << need << " tp1: " << s1 << " tp2: " << s2 << "\n";
    if((s1+s2)<=need)
    {
        cout << hap << "\n";
        return 0;
    }
    int m1 = cnt1%k, m2=cnt2%k, ans1=hap, ans2=hap;
    i = 0;
    while(m1>0 && i<n)
    {
        int s = vec[i].f.ss, a = vec[i].ss.f, b = vec[i].ss.ss, diff = vec[i].f.f;
        if(a>b)
        {
            ans1 -= (min(s,m1)*diff);
            m1 -= min(s,m1);
        }
        i++;
    }
    //cout << "make 1 into 2: " << ans1 << "\n";
    i = 0;
    while(m2>0 && i<n)
    {
        int s = vec[i].f.ss, a = vec[i].ss.f, b = vec[i].ss.ss, diff = vec[i].f.f;
        if(b>=a)
        {
            ans2 -= (min(s,m2)*diff);
            m2 -= min(s,m2);
        }
        i++;
    }
    //cout << "make 2 into 1: " << ans2 << "\n";
    cout << max(ans1,ans2) << "\n";
    return 0;
}
