#include <bits/stdc++.h> // 모든 헤더파일

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
typedef pair<ll, ll> pi; // 템플릿 종료

/* - GLOBAL VARIABLES ---------------------------- */
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int GetReplascePos(vi& increasingNums, int num) { // 각 증가하는 수열의 포지션을 변경
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
void ReplaceMaxIncreasingNums(vi& increasingNums, vi& maxIncreasingNums, int curPos) { // 최대 증가 부분수열을 구함
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

	for ( int i = 0; i < n; i++ ) { // 현재 숫자가 증가한다면 증가수열에 추가
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

	for ( int i = savedIncreasingNums.size() - 1; i >= 0; i-- ) { // 현재 쌓아놓은 증가하는 부분수열을 찾기
		for ( int j = savedIncreasingNums[i].size() - 1; j >= 0; j-- ) {
			if ( savedIncreasingNums[i][j] > maxIdx ) continue;
			maxIdx = savedIncreasingNums[i][j];
			break;
		}
		res.push_back(maxIdx);
	}

	cout << res.size() << endl; // 가장 긴 부분수열의 길이 출력

	for ( int i = res.size() - 1; i >= 0; i-- ) { // 가장 긴 부분수열 출력
		cout << nums[res[i]] << ' ';
	}
	cout << endl;

    return 0;
}
