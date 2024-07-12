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

	int n; cin >> n;
	vi nums(pow(2, n)); for ( auto &nn: nums ) cin >> nn;
	vi res;
	map<int, int> current, target;

	sort(all(nums));

	current.insert({0, 1});
	
	for ( auto curNum: nums ) {
		auto foundCurrent = current.find(curNum);
		auto foundTarget = target.find(curNum);
		if ( foundTarget == target.end() ) {
			target.insert({curNum, 1});
		} else {
			foundTarget->se++;
		}

		foundTarget = target.find(curNum);

		if ( foundCurrent == current.end() || foundCurrent->se < foundTarget->se ) {
			res.push_back(curNum);
			map<int, int> additionalMap;
			for ( auto c: current ) {
				int newNum = c.fi + curNum;
				auto foundNewNum = current.find(newNum);

				if ( foundNewNum == current.end() ) {
					auto foundAdditionalMap = additionalMap.find(newNum);
					if ( foundAdditionalMap == additionalMap.end() ) {
						additionalMap.insert({newNum, c.se});
						continue;
					}

					foundAdditionalMap = additionalMap.find(newNum);
					foundAdditionalMap->se ++;
					continue;
				}

				for ( int i = 0; i < c.se; i++ ) {
					foundNewNum->se ++;
				}
			}
			current.insert(all(additionalMap));
		}
	}

	for ( auto r: res  ) {
		cout << r << ' ';
	}
	cout << endl;

	

    return 0;
}
