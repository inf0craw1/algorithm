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
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int GetReplascePos(vi& increasingNums, int num) {
	int s = 0, e = increasingNums.size() - 1;
	int minPos = e;

	while ( s <= e ) {
		int mid = ( s + e ) / 2;

		if ( increasingNums[mid] >= num ) {
			minPos = min(minPos, mid);
			e = mid - 1;
			continue;
		}
		s = mid + 1;
	}

	return minPos;
}
void ReplaceMaxIncreasingNums(vi& increasingNums, vi& maxIncreasingNums, int curPos) {
	if ( curPos == 0 ) return;
	if ( maxIncreasingNums[curPos-1] >= maxIncreasingNums[curPos] ) {
		maxIncreasingNums[curPos-1] = increasingNums[curPos-1];
		ReplaceMaxIncreasingNums(increasingNums, maxIncreasingNums, curPos-1);
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n; cin >> n;
	vi nums(n); for ( auto &x: nums ) cin >> x;
	vi increasingNums, maxIncreasingNums;
	vector<vi> savedIncreasingNums;

	for ( int i = 0; i < n; i++ ) {
		if ( increasingNums.empty() || increasingNums.back() < nums[i] ) {
			increasingNums.push_back(nums[i]);
			savedIncreasingNums.push_back({i});
			continue;
		} 

		int pos = GetReplascePos(increasingNums,nums[i]);
		increasingNums[pos] = nums[i];
		savedIncreasingNums[pos].push_back(i);
	}

	vi res;
	int maxIdx = INF;

	for ( int i = savedIncreasingNums.size() - 1; i >= 0; i-- ) {
		for ( int j = savedIncreasingNums[i].size() - 1; j >= 0; j-- ) {
			if ( savedIncreasingNums[i][j] > maxIdx ) continue;
			maxIdx = savedIncreasingNums[i][j];
			break;
		}
		res.push_back(maxIdx);
	}

	cout << res.size() << endl;

	for ( int i = res.size() - 1; i >= 0; i-- ) {
		cout << nums[res[i]] << ' ';
	}
	cout << endl;

    return 0;
}
