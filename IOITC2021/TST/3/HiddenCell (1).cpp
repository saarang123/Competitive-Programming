#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool doesPathExist(const vector<string>& M);//Do not change this line

// Do NOT read anything from stdin or write something to stdout/stderr
//You are free to add variables and functions at global scope here
// If you use global variables, remember to initialize them in the findHiddenCell() function.

int n;
vector<string> m;

void fill(int j, char c) {
	for(int i = j; i < n; i++)
		m[j][i] = c;
	for(int i = j; i < n; i++)
		m[i][j] = c;
}


vector<string> fillfor(int x, int y) {
	vector<string> query(n, string(n, '0'));
	for(int i = 0; i <= x; i++)
		query[i][0] = '1';
	for(int i = 0; i < y; i++)
		query[x][i] = '1';
	for(int i = x + 1; i < n; i++)
		query[i][y] = '1';
	for(int i = y; i < n; i++)
		query[n - 1][i] = '1';
	return query;
}

pair<int, int> findHiddenCell(int N){
    n = N;
    m.assign(n, string(n, '1'));
    vector<int> row;
    for(int i = 1; i < n - 1; i++)
    	row.push_back(i);
    shuffle(row.begin(), row.end(), rng);
    int found = -1;
    for(int r : row) {
    	fill(r, '0');
    	//cout << r << ": ";
    	bool b = doesPathExist(m);
    	if(b) {
    		found = r; break;
    	}
    	fill(r, '1');
    }
    vector<array<int, 2>> check;
    for(int i = 1; found < 0 && i < n - 1; i++)
    	check.push_back({i, i});
    if(found < 0)
    	found = n;
    for(int i = found; i + 1 < n; i++) if(found > 0 && found < n - 1 && i > 0 && i < n - 1) {
    	check.push_back({found, i});
    	check.push_back({i, found});
    }
    sort(check.begin(), check.end());
    check.resize(unique(check.begin(), check.end()) - check.begin());
    shuffle(check.begin(), check.end(), rng);

    for(auto &[x, y] : check) {
    	//cout << "Checking for: " << x << ' ' << y << endl;
    	if(doesPathExist(fillfor(x, y)))
    		return make_pair(x, y);
    }
    return make_pair(-1, -1);
}