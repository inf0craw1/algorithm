#include <iostream>
#include <vector>

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
int row, col, item, temp, sum = 0, avg = 0;
int maxLevel = 0, minTime = 2e9;
vector<vector<int>> mapp;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
pii GetBlocksData(int level) {
	int needToBreak = 0, needToFill = 0;

	for ( int i = 0; i < row; i++ ) {
		for ( int j = 0; j < col; j++ ) {
			if ( mapp[i][j] < level ) {
				needToFill += level - mapp[i][j];
				continue;
			}
			needToBreak += mapp[i][j] - level;
		}
	}
	return make_pair(needToBreak, needToFill);
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);
	cin >> row >> col >> item;

	for ( int i = 0; i < row; i++ ) {
		vector<int> tempRow;

		for ( int j = 0; j < col; j++ ) {
			cin >> temp;

			sum += temp;
			tempRow.push_back(temp);
		}
		mapp.push_back(tempRow);
	}

	avg = sum / row / col;

	for ( int i = avg; i <= 256; i++ ) {
		pii blocksData = GetBlocksData(i);
		int needToBreak = blocksData.fi;
		int needToFill = blocksData.se;
		int processTime = needToBreak * 2 + needToFill;

		if ( needToFill > needToBreak + item ) break;
		if ( minTime < processTime ) break;
		maxLevel = i;
		minTime = min(minTime, processTime);
	}
	
	cout << minTime << ' ' << maxLevel << endl;

    return 0;
}
