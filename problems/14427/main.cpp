#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define INF 0x7fffffff
#define LINF 0x7fffffffffffffff
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

/* - GLOBAL VARIABLES ---------------------------- */
vi tree, nums, indexes;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int TreeInit(int start, int end, int index) {

	if ( start == end ) {
		indexes[index] = start; 
		tree[index] = nums[start];
		return tree[index];
	}
	int mid = (start + end) / 2;

	int res1 = TreeInit(start, mid, index*2);
	int res2 = TreeInit(mid+1, end, index*2+1);

	if ( !res1 ) res1 = INF;
	if ( !res2 ) res2 = INF;

	if ( res1 <= res2 ) {
		indexes[index] = indexes[index*2];
		tree[index] = res1;
		return tree[index];
	}
	indexes[index] = indexes[index*2+1];
	tree[index] = res2;
	return tree[index];
}
int UpdateTree(int start, int end, int index, int targetIdx, int updateNum) {
	
	if ( start > targetIdx || end < targetIdx ) return tree[index];

	if ( start == end ) {
		tree[index] = updateNum;
		indexes[index] = targetIdx;
		return tree[index];
	}
	int mid = (start + end) / 2;
	int res1 = UpdateTree(start, mid, index*2, targetIdx, updateNum );
	int res2 = UpdateTree(mid+1, end, index*2+1, targetIdx, updateNum);
	
	if ( !res1 ) res1 = INF;
	if ( !res2 ) res2 = INF;

	if ( res1 <= res2 ) {
		tree[index] = res1;
		indexes[index] = indexes[index*2];
		return tree[index];
	}
	tree[index] = res2;
	indexes[index] = indexes[index*2+1];
	return tree[index];
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n; cin >> n;
	int size = 1;
	while ( size < n ) {
		size *= 2;
	}
	size *= 2;
	indexes = vi(size+1, 0);
	tree = vi(size+1, 0);
	nums = vi(1, 0);
	for ( int i = 0; i < n; i++ ) {
		int temp; cin >> temp;
		nums.push_back(temp);
	}
	
	TreeInit(0, n, 1);
	int queries; cin >> queries;

	for ( int i = 0; i < queries; i++ ) {
		int curQ; cin >> curQ;
		
		if ( curQ == 2 ) {
			cout << indexes[1] << endl;
			continue;
		}
		int targetIdx, targetNum; cin >> targetIdx >> targetNum;
		UpdateTree(0, n, 1, targetIdx, targetNum);
	}

    return 0;
}
