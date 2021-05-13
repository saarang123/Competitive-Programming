#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");
	int i, j, n, m, a[101][2], b[101][2];
	a[0][0] = 0;
	b[0][0] = 0;
	fin >> n >> m;
	for(i=1; i<=n; i++)
	    fin >> a[i][0] >> a[i][1];
	for(j=1; j<=m; j++)
	    fin >> b[j][0] >> b[j][1];
	for(i=2; i<=n; i++)
	    a[i][0] += a[i-1][0];
	for(i=2; i<=m; i++)
	    b[i][0] += b[i-1][0];
	int ans = 0, l1, s1;
	for(i=0; i<m; i++)
	{
	    l1 = b[i][0];
	    s1 = b[i+1][1];
	    j=1;
        while(l1>a[j][0] and j<=n)
	        j++;
	    int temp = s1-a[j][1];
	    ans = max(ans, temp);
	}
	fout << ans << "\n";
	return 0;
}