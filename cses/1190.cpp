#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
 
struct data
{
    int sum,pref,suf,ans;
};
 
 
const int N = 2e5+3;
int n,m;
struct data t[4*N];
 
struct data make_data(int v)
{
    struct data res;
    res.sum = v;
    res.pref = res.suf = res.ans = max(v,0ll);
    return res;
}
 
struct data combine(struct data l, struct data r)
{
    struct data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum+r.pref);
    res.suf = max(r.suf, r.sum+l.suf);
    res.ans = max(max(l.ans, r.ans), l.suf + r.pref);
    return res;
}
 
void build(int a[], int v, int tl, int tr)
{
    if(tl==tr)
        t[v] = make_data(a[tl]);
    else
    {
        int tm = (tl+tr) >> 1;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
 
void update(int v, int tl, int tr, int pos, int val)
{
    if(tl==tr)
    {
        t[v] = make_data(val);
    }
    else
    {
        int tm = (tl+tr) >> 1;
        if(pos>tm) update(2*v+1, tm+1, tr, pos, val);
        else update(2*v, tl, tm, pos, val);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
}
 
void update(int pos, int val)
{
    update(1,1,n,pos,val);
}
 
void solve_case()
{
    int i,j,k;
    cin >> n >> m;
    int a[n+2];
    for(i=1; i<=n; i++) cin >> a[i];
    for(i=1; i<=4*n;i++) t[i] = make_data(0);
    build(a,1,1,n);
    while(m--)
    {
        cin >> j >> k;
        update(j,k);
        cout << t[1].ans << "\n";
    }
}
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}