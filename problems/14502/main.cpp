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
int height, width;
vector<vi> mapp;
vector<pi> zeroPositions, virusPositions, directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pi pos) {
	if ( pos.fi < 0 || pos.fi >= height || pos.se < 0 || pos.se >= width ) return 0;
	return 1;
}
int GetSafetyZone(vector<int> pos) {
	vector<vi> curMap = mapp;
	for ( auto p: pos ) {
		curMap[zeroPositions[p].fi][zeroPositions[p].se] = 1;
	}

	vector<pi> q = virusPositions;

	while ( q.size() ) {
		pi curPos = q.back();
		q.pop_back();

		for ( auto d: directions ) {
			pi newPos = make_pair(curPos.fi + d.fi, curPos.se + d.se);
			if ( !IsSafe(newPos) ) continue;
			if ( curMap[newPos.fi][newPos.se] == 0 ) {
				curMap[newPos.fi][newPos.se] = 2;
				q.push_back(newPos);
			}
		}
	}

	int cnt = 0;
	for ( int i = 0; i < height; i++ ) {
		for ( int j = 0; j < width; j++ ) {
			if ( curMap[i][j] == 0 ) cnt ++;
		}
	}

	return cnt;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> height >> width;

	for ( int i = 0; i < height; i++ ) {
		vi tempRow;
		for ( int j = 0; j < width; j++ ) {
			int temp; cin >> temp;
			tempRow.push_back(temp);
			if ( !temp ) zeroPositions.push_back(make_pair(i, j));
			if ( temp == 2 ) virusPositions.push_back(make_pair(i, j));
		}
		mapp.push_back(tempRow);
	}

	int maxi = 0;

	for ( int i = 0; i < zeroPositions.size(); i++ ) {
		for ( int j = i + 1; j < zeroPositions.size(); j++ ) {
			for ( int k = j + 1; k < zeroPositions.size(); k++ ) {
				maxi = max(maxi, GetSafetyZone({i, j, k}));
			}
		}
	}

	cout << maxi << endl;


    return 0;
}
