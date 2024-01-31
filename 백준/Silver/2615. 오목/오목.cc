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
int temp;
vector<pair<pii, pii>> directions = {{{-1, 0}, {1, 0}}, {{0, -1}, {0, 1}}, {{-1,-1}, {1,1}}, {{1, -1}, {-1, 1}}};
vector<vector<int>> mapp;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pii pos) {
	if ( pos.fi < 0 || pos.fi >=19 || pos.se < 0 || pos.se >= 19) return 0;
	return 1;
}
int CountDirection(pii curPos, pii direction) {
	int cnt = 0;
	int color = mapp[curPos.fi][curPos.se];
	pii newPos = curPos;

	while ( IsSafe(newPos) && mapp[newPos.fi][newPos.se] == color ) {
		cnt ++;
		newPos.fi += direction.fi;
		newPos.se += direction.se;
	}

	return cnt;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);


	for ( int i = 0; i < 19; i++ ) {
		vector<int> tempRow;
		for ( int j = 0; j < 19; j++ ) {
			cin >> temp;
			tempRow.push_back(temp);
		}
		mapp.push_back(tempRow);
	}

	for ( int j = 0; j < 19; j++ ) {
		for ( int i = 0; i < 19; i++ ) {
			if ( mapp[i][j] == 0 ) continue;
			int color = mapp[i][j];
			for ( auto d: directions ) {
				pii backward = d.fi;
				pii forward = d.se;
				pii rightBackPos = make_pair(i + backward.fi, j + backward.se);
				if ( IsSafe(rightBackPos) && mapp[rightBackPos.fi][rightBackPos.se] == color ) continue;
				int cnt = CountDirection(make_pair(i, j), forward);
				if ( cnt == 5 ) {
					cout << color << endl << i+1 << ' ' << j+1 << endl;
					return 0;
				}
			}
		}
	}

	cout << 0 << endl;

    return 0;
}
