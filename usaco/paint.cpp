#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("paint.in");
    ofstream fout("paint.out");
    int a,b,c,d, j,i;
    fin >> a >> b >> c >> d;
    if((c<=b && c>=a) || (d>=a && d<=b) || (a<=c && a>=d) || (b>=c && b<=d))
    {
        i = min(min(a,b), min(c,d));
        j = max(max(a,b), max(c,d));
        fout << j-i << "\n";
    }
    else
        fout << b-a + d-c << "\n";
	return 0;
}