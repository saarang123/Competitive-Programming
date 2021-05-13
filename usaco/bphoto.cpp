#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
// of elements smaller tban or equal to x.
#include<bits/stdc++.h>
using namespace std;

// structure to hold queries
struct Query
{
    int l, r, x, idx;
};

// structure to hold array
struct ArrayElement
{
    int val, idx;
};

// bool function to sort queries according to k
bool cmp1(Query q1, Query q2)
{
    return q1.x < q2.x;
}

// bool function to sort array according to its value
bool cmp2(ArrayElement x, ArrayElement y)
{
    return x.val < y.val;
}

// updating the bit array
void update(int bit[], int idx, int val, int n)
{
    for (; idx<=n; idx +=idx&-idx)
        bit[idx] += val;
}

// querying the bit array
int query(int bit[], int idx, int n)
{
    int sum = 0;
    for (; idx > 0; idx -= idx&-idx)
        sum += bit[idx];
    return sum;
}

void answerQueries(int n, Query queries[], int q,
                              ArrayElement arr[])
{
    // initialising bit array
    int bit[n+1];
    memset(bit, 0, sizeof(bit));

    // sorting the array
    sort(arr, arr+n, cmp2);

    // sorting queries
    sort(queries, queries+q, cmp1);

    // current index of array
    int curr = 0;

    // array to hold answer of each Query
    int ans[q];

    // looping through each Query
    for (int i=0; i<q; i++)
    {
        // traversing the array values till it
        // is less than equal to Query number
        while (arr[curr].val <= queries[i].x && curr<n)
        {
            // updating the bit array for the array index
            update(bit, arr[curr].idx+1, 1, n);
            curr++;
        }

        // Answer for each Query will be number of
        // values less than equal to x upto r minus
        // number of values less than equal to x
        // upto l-1
        ans[queries[i].idx] = query(bit, queries[i].r+1, n) -
                              query(bit, queries[i].l, n);
    }

    // printing answer for each Query
    for (int i=0 ; i<q; i++)
        cout << ans[i] << endl;
}

// driver function
int main()
{
    // size of array
    int n = 4;

    // initialising array value and index
    ArrayElement arr[n];
    arr[0].val = 2;
    arr[0].idx = 0;
    arr[1].val = 3;
    arr[1].idx = 1;
    arr[2].val = 4;
    arr[2].idx = 2;
    arr[3].val = 5;
    arr[3].idx = 3;

    // number of queries
    int q = 2;
    Query queries[q];
    queries[0].l = 0;
    queries[0].r = 2;
    queries[0].x = 2;
    queries[0].idx = 0;
    queries[1].l = 0;
    queries[1].r = 3;
    queries[1].x = 5;
    queries[1].idx = 1;

    answerQueries(n, queries, q, arr);

    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("bphoto.in");
    ofstream fout("bphoto.out");
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    ArrayElement arr[n];
    RE(i,n)
    {
        cin >> arr[i].val;
        arr[i].idx = i-1;
    }

    // number of queries
    int q = 2;
    Query queries[q];
    queries[0].l = 0;
    queries[0].r = 2;
    queries[0].x = 2;
    queries[0].idx = 0;
    queries[1].l = 0;
    queries[1].r = 3;
    queries[1].x = 5;
    queries[1].idx = 1;

    answerQueries(n, queries, q, arr);
    return 0;
}
