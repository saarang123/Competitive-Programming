#include <bits/stdc++.h>
using namespace std;
const int MXN = 1000 * 1000 * 1000 + 3;
const int ID = -MXN;
struct Node {
	Node *l, *r;
	int lazy, sum, cmax;
	Node() : lazy(ID), sum(0), cmax(0) {}
	Node(int _lazy, int _sum, int _cmax) : lazy(_lazy), sum(_sum), cmax(cmax) {}
};

struct SegTree {
	deque<Node> buffer;

	Node* newnode() {
		return &buffer.emplace_back();
	}

	void push(Node *&v, int tl, int tr) {
		if(v && v->lazy != ID) {
			v->sum = (tr - tl + 1) * v->lazy;
			if(tl == tr)
				return v->lazy = ID, void();
			v->l->lazy = v->lazy;
			v->r->lazy = v->lazy;
			v->lazy = ID;
		}
	}

	void update(Node *&v, int tl, int tr, int l, int r, int x) {
		if(l > tr || r < tl) 
			return;
		if(!v) 
			v = newnode();
		if(l <= tl && tr <= r) {
			cout << "adding lazy on: " << tl << ' ' << tr << endl;
			v->lazy = x;
			push(v, tl, tr);
			return;
		}
		cout << "Range: (" << tl << ", " << tr << ") with sum: " << v->sum << endl;
		if(!v->l)
			v->l = newnode();
		if(!v->r)
			v->r = newnode();
		push(v, tl, tr);
		int tm = (tl + tr) >> 1;
		update(v->l, tl, tm, l, r, x);
		update(v->r, tm + 1, tr, l, r, x);
		v->sum = v->l->sum + v->r->sum;
		v->cmax = max(v->sum, v->l->cmax);
	}

	int query(Node *v, int tl, int tr, int h) {
		if(tl == tr)
			return tl;
		if(!v)
			v = newnode();
		if(!v->l)
			v->l = newnode();
		if(!v->r)
			v->r = newnode();
		push(v, tl, tr);
		cout << "Range: (" << tl << ", " << tr << ") with sum: " << v->sum << endl;
		if(tl + 1 == tr) {

		}
		int tm = (tl + tr) >> 1;
		if(v->l->sum >= h)
			return query(v->l, tl, tm, h);
		else
			return query(v->r, tm + 1, tr, h - v->sum);
	}

	void update(int l, int r, int x) {
		cout << "update: " << endl;
		update(root, 0, n, l, r, x);
	}

	int query(int h) {
		cout << "query: " << endl;
		return query(root, 0, n, h);
	}

	Node *root;
	int n;
	SegTree(int _n) : n(_n) {}
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/code/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/code/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    SegTree st(n);
    cout << "Here" << endl;
    char c = 's';
    while(c != 'E') {
    	cin >> c;
    	if(c == 'I') {
    		int l, r, x;
    		cin >> l >> r >> x;
    		st.update(l, r, x);
    	} else if(c == 'Q') {
    		int x; cin >> x;
    		cout << st.query(x) << endl;
    	}
    }
    return 0;
}