#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int, int>

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
vector<int> res;
vector<vector<int>> mmap;
vector<pii> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
pii FindFirstHouse() {
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			if ( mmap[i][j] == 1 ) return make_pair(i, j);
		}
	}
	return make_pair(-1, -1);
}

bool IsSafe(pii location) {
	if ( location.fi < 0 || location.fi >= n || location.se < 0 || location.se >= n ) return 0;
	return 1;
}

pii GetSumOfPair(pii p1, pii p2) {
	return make_pair(p1.fi + p2.fi, p1.se + p2.se);
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		vector<int> row;
		string str;
		cin >> str;
		for ( int j = 0; j < n; j++ ) {
			row.push_back(str[j] - '0');
		}
		mmap.push_back(row);
	}

	while (true) {
		pii firstHouse = FindFirstHouse();

		if ( firstHouse.fi == -1 ) break;

		int cnt = 0;
		queue<pii> houses;
		houses.push(firstHouse);
		while ( !houses.empty() ) {

			pii currentLocation = houses.front();
			houses.pop();
			if ( !mmap[currentLocation.fi][currentLocation.se] ) continue;
			mmap[currentLocation.fi][currentLocation.se] = 0;
			cnt ++;

			for ( int i = 0; i < 4; i++ ) {
				pii newLocation = GetSumOfPair(currentLocation, directions[i]);
				if ( IsSafe(newLocation) && mmap[newLocation.fi][newLocation.se] ) {
					houses.push(newLocation);
				}
			}
		}
		res.push_back(cnt);
	}
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for ( auto r: res ) {
		cout << r << endl;
	}

	return 0;
}
