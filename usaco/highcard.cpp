#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("highcard.in");
	ofstream fout("highcard.out");
	int i,j,n, a[100005], cnt=0;
	memset(a, 0, sizeof a);
	fin >> n;
	int b[n+1], c[n+1];
	for(i=1; i<=n; i++)
	{
	    fin >> j;
	    a[j] = 1;
	}
	j=1;
	int k=1;
	for(i=1; i<=2*n; i++)
	{
	    if(a[i]==0) {c[j]=i; j++;}
	    if(a[i]==1) {b[k]=i; k++;}
	}
	/*for(i=1; i<=n; i++)
	    cout << b[i] << " ";
	cout << endl;
	for(i=1; i<=n; i++)
	    cout << c[i] << " ";*/
	cout << endl;
	i=1; j=1;
	while(j<=n && i<=n)
	{
	    if(c[j]>b[i])  {cnt++; i++;}
	    j++;
	}
	fout << cnt << endl;
	return 0;
}