#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;

int possible(int l[], int k, int t, int n)
{
    set<int> s;
    int last = 0;
    for(int i=0; i<n; i++)
    {
        if(s.size()==k)
        {
            last = *s.begin();
            s.erase(s.begin());
        }
        if(l[i]+last > t)
            return false;
        s.insert(l[i]+last);
    }
    return true;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");
    //freopen("input.txt", "r", stdin);
    int n,i,j, t;
    //set<int> pres;
    cin >> n >> t;
    int a[n];
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }
    int m1=1, m2 = n;
    while(m1!=m2)
    {

        int mid = (m1+m2)/2;

        if(possible(a, mid, t, n))
            m2 = mid;
        else
            m1 = mid+1;
        //cout << m1 << " " << m2 << " " << mid << "\n";
    }
    cout << m1 << "\n";
    return 0;
}
