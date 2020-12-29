#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("bcount.in");
	ofstream fout("bcount.out");
	int i,j,n,q;
	fin >> n >> q;
	int a[n+1], b[n+1], c[n+1];
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(c, 0, sizeof c);
	
	for(i=1; i<=n; i++)
	{
	    fin >> j;
	    if(j==1)
	    {
	        a[i] += a[i-1]+1;
	        b[i] += b[i-1];
	        c[i] += c[i-1];
	    }
	    else if(j==2)
	    {
	        a[i] += a[i-1];
	        b[i] += b[i-1]+1;
	        c[i] += c[i-1];
	    }
	    else
	    {
	        a[i] += a[i-1];
	        b[i] += b[i-1];
	        c[i] += c[i-1]+1;
	    }
	}
	/*for(i=1; i<=n; i++)
	    cout << a[i] << " ";
	cout << endl;
	for(i=1; i<=n; i++)
	    cout << b[i] << " ";
	cout << endl;
	for(i=1; i<=n; i++)
	    cout << c[i] << " ";
	cout << endl;*/
	
	for(i=0; i<q; i++)
	{
	    int l,r;
	    fin >> l >> r;
	    l--;
	    fout << a[r]-a[l] << " ";
	    fout << b[r]-b[l] << " ";
	    fout << c[r]-c[l] << "\n";
	}
    return 0;
}