#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool doesPathExist(const vector<string>& M);//Do not change this line

// Do NOT read anything from stdin or write something to stdout/stderr
//You are free to add variables and functions at global scope here
// If you use global variables, remember to initialize them in the findHiddenCell() function.

int n, found = -1;
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

void ok(vector<pair<int, int>> q, char c) {
	for(auto &[x, y] : q)
		m[x][y] = c;
}

pair<int, int> fix(vector<pair<int, int>> cand) {
	if(cand.size() == 1)
		return cand.back();
	vector<pair<int, int>> newQ[2], newC[2];
	for(int i = 0; i < cand.size(); i++) {
		newC[i & 1].push_back(cand[i]);
		if(cand[i].first == found) {
			newQ[i & 1].push_back({found == 1 ? found + 1 : found - 1, cand[i].second});
		} else {
			newQ[i & 1].push_back({cand[i].first, found == 1 ? found + 1 : found - 1});
		}
	}
	m = vector<string>(n, string(n, '1'));
	fill(found, '0');
	ok(newQ[0], '1');
	bool b = doesPathExist(m);
	if(b)
		return fix(newC[0]);
	return fix(newC[1]);
}

pair<int, int> findHiddenCell(int N){
    n = N;
    m.assign(n, string(n, '1'));
    vector<int> row;
    for(int i = 1; i < n - 1; i++)
    	row.push_back(i);
    shuffle(row.begin(), row.end(), rng);
    for(int r : row) {
    	fill(r, '0');
    	//cout << r << ": ";
    	bool b = doesPathExist(m);
    	if(b) {
    		found = r; break;
    	}
    	fill(r, '1');
    }
    cout << found << endl;
    vector<pair<int, int>> check, other;
    for(int i = 1; found < 0 && i < n - 1; i++)
    	check.push_back({i, i});
    shuffle(check.begin(), check.end(), rng);

    if(found < 0) {
    	for(auto &[x, y] : check) {
    	//cout << "Checking for: " << x << ' ' << y << endl;
    		if(doesPathExist(fillfor(x, y)))
    			return make_pair(x, y);
    	}
    }
    for(int i = found; i + 1 < n; i++) if(found > 0 && found < n - 1 && i > 0 && i < n - 1) {
    	if(i != found)
    		other.push_back({found, i});
    	if(i != found)
    		other.push_back({i, found});
    }
    //shuffle(other.begin(), other.end(), rng);
    return fix(other);
}