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
int height, width, numberOfSharks;
int curTime = 0, res = 0;
vector<vi> sharks;
vector<vector<pi>> mapp;
vector<pi> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vi opositeDirection = {1, 0, 3, 2};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pi pos) {
	if ( pos.fi < 0 || pos.fi >= height || pos.se < 0 || pos.se >= width ) return 0;
	return 1;
}
int GetShark() {
	for ( int i = 0; i < height; i++ ) {
		if ( mapp[i][curTime].fi == curTime && sharks[mapp[i][curTime].se][0] != -1 ) {
			int curSharkIdx = mapp[i][curTime].se;
			int curSharkSize = sharks[curSharkIdx][4];
			mapp[i][curTime] = make_pair(-1, -1);
			sharks[curSharkIdx][0] = -1;
			return curSharkSize;
		}
	}
	return 0;
}
void MoveSharks() {
	for ( int i = 0; i < numberOfSharks; i++ ) {
		if ( sharks[i][0] == -1 ) continue;

		pi curPos = make_pair(sharks[i][0], sharks[i][1]);
		int curSpeed = sharks[i][2];
		int curDir = sharks[i][3];
		int curMapSize = directions[curDir].se == 0 ? height : width;
		int curMove = curSpeed % ((curMapSize - 2) * 2 + 2);
		int curSize = sharks[i][4];

		pi newPos = make_pair(curPos.fi + directions[curDir].fi * curMove, curPos.se + directions[curDir].se * curMove);

		while ( !IsSafe(make_pair(newPos.fi, 0)) ) {
			if ( newPos.fi >= height ) {
				newPos.fi = (height - 1) * 2 - newPos.fi;
			} else {
				newPos.fi *= -1;
			}
			curDir = opositeDirection[curDir];
		}

		while ( !IsSafe(make_pair(0, newPos.se)) ) {
			if ( newPos.se >= width ) {
				newPos.se = (width - 1) * 2 - newPos.se;
			} else {
				newPos.se *= -1;
			}
			curDir = opositeDirection[curDir];
		}

		if ( mapp[newPos.fi][newPos.se].fi == curTime + 1 ) {
			if ( curSize < sharks[mapp[newPos.fi][newPos.se].se][4] ) {
				sharks[i][0] = -1;
				continue;
			} else {
				sharks[mapp[newPos.fi][newPos.se].se][0] = -1;
			}
		}

		mapp[newPos.fi][newPos.se] = make_pair(curTime+1, i);
		sharks[i][0] = newPos.fi;
		sharks[i][1] = newPos.se;
		sharks[i][3] = curDir;
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> height >> width >> numberOfSharks;
	mapp.resize(height, vector<pi> (width, make_pair(-1, -1)));

	for ( int i = 0; i < numberOfSharks; i++ ) {
		int row, col, speed, dir, size; cin >> row >> col >> speed >> dir >> size;
		sharks.push_back({row-1, col-1, speed, dir-1, size});
		mapp[row-1][col-1] = make_pair(0, i);
	}

	for ( curTime = 0; curTime < width; curTime++ ) {
		res += GetShark();
		MoveSharks();
	}

	cout << res << endl;
    return 0;
}
