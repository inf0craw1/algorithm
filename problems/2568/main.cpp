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
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int num; cin >> num;
	vector<pi> nums;
	vi LIS;
	vector<vi> LISOrders(num, vi(0, 0));

	for ( int i = 0; i < num; i++ ) {
		int n1, n2; cin >> n1 >> n2;

		nums.push_back(make_pair(n1, n2));
	}

	sort(all(nums));

	LIS.push_back(nums[0].se);
	LISOrders[0].push_back(0);

	for ( int i = 1; i < num; i++ ) {
		int cur = nums[i].se;
		int size = LIS.size();
		if ( size == 0 || LIS[size - 1] < cur ) {
			LIS.push_back(cur);
			LISOrders[size].push_back(i);
			continue;
		}

		for ( int j = 0; j < size; j++ ) {
			if ( LIS[j] > cur ) {
				LIS[j] = cur;
				LISOrders[j].push_back(i);
				break;
			}
		}
	}

	int mini = INF;
	vector<pi> ans;

	for ( int i = num-1; i >= 0; i-- ) {
		int chk = 0;

		for ( int j = LISOrders[i].size() - 1; j >= 0; j-- ) {
			if ( chk == 0 ) {
				if ( mini > LISOrders[i][j] ) {
					mini = LISOrders[i][j];
					chk = 1;
					continue;
				}
				ans.push_back(nums[LISOrders[i][j]]);
				continue;
			}
			ans.push_back(nums[LISOrders[i][j]]);
		}
	}

	sort(all(ans));

	cout << ans.size() << endl;
	for ( auto a: ans ) {
		cout << a.fi << endl;
	}


    return 0;
}
