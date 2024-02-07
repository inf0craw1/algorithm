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

	int stuff, maxWeight;
	int stuffWeight, stuffSatisfaction, stuffCount;
	vector<vector<int>> dp;

	cin >> stuff >> maxWeight;

	dp.resize(stuff+1, vector<int> (maxWeight+1, 0));

	for ( int i = 1; i <= stuff; i++ ) {
		cin >> stuffWeight >> stuffSatisfaction >> stuffCount;

		for ( int j = 1; j <= maxWeight; j++ ) {
			int maxCurrentStuffCount = min((j / stuffWeight), stuffCount);
			int maxCurrentStuffWeight = maxCurrentStuffCount * stuffWeight;
			int maxi = dp[i-1][j];

			maxi = max(maxi, maxCurrentStuffCount * stuffSatisfaction + dp[i-1][j - maxCurrentStuffWeight]);
		
			dp[i][j] = maxi;
		}
	}

	for ( auto row: dp ) {
		for ( auto r: row ) {
			cout << r << ' ';
		}
		cout << endl;
	}

	cout << dp[stuff][maxWeight] << endl;
    return 0;
}
