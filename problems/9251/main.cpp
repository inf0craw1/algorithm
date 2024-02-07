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

	string str1, str2;
	vector<vector<int>> dp;

	cin >> str1 >> str2;

	dp.resize(str2.size()+1, vector<int> (str1.size()+1, 0));

	for ( int i = 1; i <= str2.size(); i++ ) {
		for ( int j = 1; j <= str1.size(); j++ ) {
			if ( str2[i-1] == str1[j-1] ) {
				dp[i][j] = dp[i-1][j-1] + 1;
				continue;
			}
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << dp[str2.size()][str1.size()] << endl;

    return 0;
}
