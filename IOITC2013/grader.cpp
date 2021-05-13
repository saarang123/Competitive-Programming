#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

void solve(int N, bool *ans);

namespace{
const int max_N = 25000; 
int Q = 300; 

bool included[max_N] = {0};

bool ans[max_N];

int N;

}

int main()
{
	int K;
	scanf("%d %d", &N, &K);
	if(K > N)
	{
		printf("Invalid input : the number of included variables cannot be more than the total number of variables.\n");
		return 0;
	}
	for(int i=0; i<K; ++i)
	{
		int x;
		scanf("%d", &x);
		if(x < 0 || x >= N)
		{
			printf("Invalid input : %d is not in the range [0, %d).\n", x, N);
			return 0;
		}
		included[x] = true; //Indices are 0-based!
	}
	
	solve(N, ans);
	
	for(int i=0; i<N; ++i)
		if(ans[i] != included[i])
		{
			fprintf(stderr, "Answer is wrong for variable %d.\n", i);
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
}

bool query(const bool *q)
{
	if( --Q < 0)
	{
		fprintf(stderr, "Too many queries.\n");
		printf("NO");
	}
	bool res = true;
	for(int i=0; i<N; ++i)
		if(included[i])
			res = res && q[i];
	return res;
}

void solve(int n, bool *ans) {
	bool q[n];
	memset(ans, false, sizeof ans);
	int cnt = 0;
	while(cnt < min(25, n)) {
		int mn = 0, mx = n - 1;
		memset(q, true, sizeof q);
		while(mn < mx) {
			int mid = (mn + mx) >> 1;
			for(int i = mn; i <= mid; i++) if(!ans[i])
				q[i] = false;
			bool x = query(q);
			if(q)
				mn = mid + 1;
			else
				mx = mid;
			for(int i = mn; i <= mid; i++)
				q[i] = true;
		}
		q[mn] = false;
	}
}