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
int mapSize, maxi = 0;
vector<vi> bannedMap, mapp;
/* ----------------------------------------------- */
/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pi pos) {
	if ( pos.fi < 0 || pos.fi >= mapSize || pos.se < 0 || pos.se >= mapSize ) return 0;
	return 1;
}
pi GetNextPossiblePos(pi lastPos) {
	int row = lastPos.fi;
	int col = lastPos.se + 1;

	for ( int j = col; j < mapSize; j++ ) {
		if ( bannedMap[row][j] && mapp[row][j] == 0 ) return make_pair(row, j);
	}

	for ( int i = row+1; i < mapSize; i++ ) {
		for  (int j = 0; j < mapSize; j++) {
			if ( bannedMap[i][j] && mapp[i][j] == 0 ) return make_pair(i, j);
		}
	}
	
	return make_pair(-1, -1);
}
void PlaceBishop(pi lastPos, int count) {
	pi nextPossiblePos = GetNextPossiblePos(lastPos);
	
	if ( nextPossiblePos.fi == -1 ) {
		maxi = max(maxi, count);
		cout << count << ' ';
		return;
	}

	for ( int i = 1; i <= mapSize; i++ ) {
		if ( IsSafe(make_pair(nextPossiblePos.fi + i, nextPossiblePos.se - i)) ) mapp[nextPossiblePos.fi + i][nextPossiblePos.se - i] ++;
		if ( IsSafe(make_pair(nextPossiblePos.fi + i, nextPossiblePos.se + i)) ) mapp[nextPossiblePos.fi + i][nextPossiblePos.se + i] ++;
	}
	PlaceBishop(nextPossiblePos, count + 1);
	for ( int i = 1; i <= mapSize; i++ ) {
		if ( IsSafe(make_pair(nextPossiblePos.fi + i, nextPossiblePos.se - i)) ) mapp[nextPossiblePos.fi + i][nextPossiblePos.se - i] --;
		if ( IsSafe(make_pair(nextPossiblePos.fi + i, nextPossiblePos.se + i)) ) mapp[nextPossiblePos.fi + i][nextPossiblePos.se + i] --;
	}
	PlaceBishop(nextPossiblePos, count);

}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> mapSize;
	mapp.resize(mapSize, vi (mapSize, 0));

	for ( int i = 0; i < mapSize; i++ ) {
		vi tempRow;
		for  (int j = 0; j < mapSize; j++) {
			int temp; cin >> temp;
			tempRow.push_back(temp);
		}
		bannedMap.push_back(tempRow);
	}

	PlaceBishop(make_pair(0, -1), 0);

	cout << maxi << endl;

    return 0;
}
