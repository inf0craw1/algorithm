#include <iostream>
#include <vector>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/* - GLOBAL VARIABLES ---------------------------- */

/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n, temp;
	
	cin >> n;

	vector<int> arr, dp(n, 1);

	for ( int i = 0; i < n; i++ ) {
		cin >> temp;

		arr.push_back(temp);

		for ( int j = 0; j < i; j++ ) {
			if ( arr[j] < arr[i] ) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		for ( auto d: dp ) {
			cout << d << ' ';
		}
		cout << endl;
	}

	cout << dp[n-1] << endl;

    return 0;
}
