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
int width, height, res;
vector<vector<int>> mapp;
vector<vector<pii>> dpMap;
vector<pii> directions = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
string temp;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pii pos) {
	if ( pos.fi < 0 || pos.fi >= height || pos.se < 0 || pos.se >= width ) return 0;
	return 1;
}
bool CheckOverwrite(pii curPos, pii newPos) {
	pii curDP = dpMap[curPos.fi][curPos.se];
	pii newDP = dpMap[newPos.fi][newPos.se];
	if ( newDP.fi == 0 && newDP.se == 0 ) return 1;
	if ( (newDP.fi == 0 && curDP.fi != 0) || (newDP.se == 0 && curDP.se != 0) ) return 1;
	return 0;
}
int FindWay(vector<vector<int>> m) {
	queue<pii> q;
	q.push(make_pair(0, 0));
	dpMap[0][0].fi = 0;
	dpMap[0][0].se = 1;

	while ( q.size() ) {
		pii curPos = q.front();

		cout << "----------------------" << endl;
		cout << curPos.fi << ' ' << curPos.se << endl;
		for ( auto row: dpMap ) {
			for ( auto r: row ) {
				cout << r.fi << ',' << r.se << ' ';
			}
			cout << endl;
		}

		q.pop();

		for ( auto d: directions ) {
			bool chk = 0;
			pii newPos = make_pair(curPos.fi + d.fi, curPos.se + d.se);
			if ( !IsSafe(newPos) ) continue;
			if ( !CheckOverwrite(curPos, newPos) ) continue;
			if ( m[newPos.fi][newPos.se] == 0 ) {
				if ( dpMap[newPos.fi][newPos.se].fi == 0 && dpMap[curPos.fi][curPos.se].fi != 0 ) {
					dpMap[newPos.fi][newPos.se].fi = dpMap[curPos.fi][curPos.se].fi + 1;
					chk = 1;
				}
				if ( dpMap[newPos.fi][newPos.se].se == 0 && dpMap[curPos.fi][curPos.se].se != 0 ) {
					dpMap[newPos.fi][newPos.se].se = dpMap[curPos.fi][curPos.se].se + 1;
					chk = 1;
				}
				if ( !chk ) continue;
			}
			if ( m[newPos.fi][newPos.se] == 1 ) {
				if ( dpMap[curPos.fi][curPos.se].se != 0 && dpMap[newPos.fi][newPos.se].fi == 0 ) {
					dpMap[newPos.fi][newPos.se].fi = dpMap[curPos.fi][curPos.se].se + 1;
					chk = 1;
				}
				if ( !chk ) continue;
			}
			if ( dpMap[newPos.fi][newPos.se].fi == 0 && dpMap[newPos.fi][newPos.se].se == 0 ) continue;
			q.push(newPos);
		}
	}
	return -1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> height >> width;

	for ( int i = 0; i < height; i++ ) {
		vector<int> tempRow;
		vector<pii> tempDPRow;
		cin >> temp;
		for ( int j = 0; j < width; j++ ) {
			tempRow.push_back(temp[j] - '0');
			tempDPRow.push_back(make_pair(0, 0));
		}
		mapp.push_back(tempRow);
		dpMap.push_back(tempDPRow);
	}

	FindWay(mapp);
	res = max(dpMap[height - 1][width - 1].fi, dpMap[height - 1][width - 1].se);
	cout << (res ? res : -1) << endl;

	for ( auto row: mapp ) {
		for ( auto r: row ) {
			cout << r << ' ';
		}
		cout << endl;
	}
	for ( auto row: dpMap ) {
		for ( auto r: row ) {
			cout << r.fi << ',' << r.se << ' ';
		}
		cout << endl;
	}
    return 0;
}

