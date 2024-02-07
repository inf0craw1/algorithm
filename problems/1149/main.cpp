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
int n; 
vector<vector<int>> prices;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n;

	int temp;

	for ( int i = 0; i < n; i++ ) {
		vector<int> tempRow;
		for ( int j = 0; j < 3; j++ ) {
			cin >> temp;
			tempRow.push_back(temp);
		}
		prices.push_back(tempRow);
	}

	for ( int i = 1; i < n; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			int mini = 2e9;
			for ( int k = 0; k < 3; k++ ) {
				if ( k == j ) continue;
				mini = min(mini, prices[i-1][k]);
			}
			prices[i][j] += mini;
		}
	}
	int mini = 2e9;
	for ( int i = 0; i < 3; i++ ) {
		mini = min(mini, prices[n-1][i]);
	}

	cout << mini << endl;

    return 0;
}
