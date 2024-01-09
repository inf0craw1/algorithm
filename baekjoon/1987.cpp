#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

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
 int row, col, maxi = 0;
 vector<vector<char>> mapp;
 vector<pair<int, int>> direction = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

int IsSafe(pair<int, int> pos) {
	if ( pos.fi < 0 || pos.fi >= row || pos.se < 0 || pos.se >= col ) {
		return 0;
	}
	return 1;
}

 void MovePiece(pair<int, int> pos, int step, set<char> trace) {
	if ( trace.size() && trace.find(mapp[pos.fi][pos.se]) != trace.end() ) {
		maxi = max(maxi, step);

		return;
	}


	trace.insert(mapp[pos.fi][pos.se]);

	for ( int i = 0; i < 4; i++ ) {
		pair<int, int> newPos = make_pair(pos.fi + direction[i].fi, pos.se + direction[i].se);
		if ( IsSafe(newPos) ) {
			MovePiece(newPos, step+1, trace);
		}
	}
 }

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	char temp;
	vector<char> temp_row, empty;
	set<char> empty_set;

	cin >> row >> col;

	for ( int i = 0; i < row; i++ ) {
		temp_row = empty;
		for ( int j = 0; j < col; j++ ) {
			cin >> temp;
			temp_row.push_back(temp);
		}
		mapp.push_back(temp_row);
	}

	MovePiece(make_pair(0, 0), 0, empty_set);

	cout << maxi << endl;

    return 0;
}
