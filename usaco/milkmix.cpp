#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;

void pour(int c1, int m1, int c2, int m2) {
  int amt = min(m1, c2 - m2);
  m1 -= amt;
  m2 += amt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ifstream fin("milkmix.in");
    ofstream fout("milkmix.out");
    ll m1,m2, m3, c1,c2,c3, i ,j;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
    for (int i = 0; i < 33; i++)
    {
        pour(c1, m1, c2, m2);
        pour(c2, m2, c3, m3);
        pour(c3, m3, c1, m1);
    }
    pour(c1, m1, c2, m2);
    cout << m1 << "\n" << m2 << "\n" << m3 << "\n";
    return 0;
}
