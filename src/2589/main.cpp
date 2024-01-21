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
int width, height, maxi = 0;
vector<vector<int>> mapp;
vector<pii> directions = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
string temp;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pii pos) {
	if ( pos.fi < 0 || pos.fi >= height || pos.se < 0 || pos.se >= width ) return 0;
	return 1;
}
void CheckLand(pii pos) {
	vector<vector<int>> tempMap = mapp;
	queue<pair<pii, int>> q;
	q.push(make_pair(pos, 0));
	tempMap[pos.fi][pos.se] = 0;

	while ( q.size() ) {
		pair<pii, int> cur = q.front();
		pii curPos = cur.fi;
		int curStep = cur.se;

		q.pop();

		for ( auto d: directions ) {
			pii newPos = make_pair(curPos.fi + d.fi, curPos.se + d.se);
			if ( IsSafe(newPos) && tempMap[newPos.fi][newPos.se] ) {
				tempMap[newPos.fi][newPos.se] = 0;
				q.push(make_pair(newPos, curStep + 1));
				maxi = max(maxi, curStep + 1);
			}
		}
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> height >> width;

	for ( int i = 0; i < height; i++ ) {
		cin >> temp;
		vector<int> tempRow;
		for ( int j = 0; j < width; j++ ) {
			if ( temp[j] == 'L' ) {
				tempRow.push_back(1);
				continue;
			}
			tempRow.push_back(0);
		}
		mapp.push_back(tempRow);
	}

	for ( int i = 0; i < height; i++ ) {
		for ( int j = 0; j < width; j++ ) {
			if ( mapp[i][j] ) {
				CheckLand(make_pair(i, j));
			}
		}
	}

	cout << maxi << endl;

    return 0;
}
