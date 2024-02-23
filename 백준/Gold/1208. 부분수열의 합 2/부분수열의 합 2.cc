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
int n, targetNum; 
vi leftNum, rightNum;
ll res1 = 0, res2 = 0, res = 0;
unordered_map<ll, ll> combinationSum;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void MakeCombination(vi& nums, int cur, vi trace) {
	if ( cur >= nums.size() ) {
		if ( trace.size() == 0 ) return;
		ll curSum = 0;
		for ( auto tt: trace ) {
			curSum += nums[tt];
		}
		if ( nums == leftNum ) {
			auto foundMap = combinationSum.find(curSum);
			if ( foundMap == combinationSum.end() ) {
				combinationSum.insert({curSum, 1});
				return;
			}
			foundMap->se ++;
		} else {
			if ( curSum == targetNum ) res++;
			auto foundMap = combinationSum.find(targetNum - curSum);
			if ( foundMap == combinationSum.end() ) return;
			res += foundMap->se;
		}
		return; 
	}
	MakeCombination(nums, cur+1, trace);
	trace.push_back(cur);
	MakeCombination(nums, cur+1, trace);
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n >> targetNum;

	for ( int i = 0; i < n/2+1; i++ ) {
		int temp; cin >> temp;
		leftNum.push_back(temp);
	}
	for (int i = 0; i < n - (n/2+1); i++) {
		int temp; cin >> temp;
		rightNum.push_back(temp);
	}

	MakeCombination(leftNum, 0, {});
	auto foundTarget = combinationSum.find(targetNum);
	if ( foundTarget != combinationSum.end() ) res += foundTarget->se;
	MakeCombination(rightNum, 0, {});

	cout << res << endl;

    return 0;
}
