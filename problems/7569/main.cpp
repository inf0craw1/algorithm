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
int x, y, z, remainTomatoes = 0, temp, maxi = 0;
vector<vector<vector<int>>> mapp;
vector<vector<int>> directions = { {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}, {0, 0, 1}, {0, 1, 0}, {1, 0, 0} };
queue<pair<vector<int>, int>> q;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(vector<int> pos) {
	if ( pos[0] < 0 || pos[0] >= z || pos[1] < 0 || pos[1] >= y || pos[2] < 0 || pos[2] >= x ) return 0;
	return 1;
}
void enripenTomatoes() {
	while ( q.size() ) {
		pair<vector<int>, int> cur = q.front();
		vector<int> curPos = cur.fi;
		int curDay = cur.se;
		q.pop();

		maxi = max(maxi, curDay);

		for ( auto d: directions ) {
			vector<int> newPos = { curPos[0] + d[0], curPos[1] + d[1], curPos[2] + d[2] };
			if ( IsSafe(newPos) && mapp[newPos[0]][newPos[1]][newPos[2]] == 0 ) {
				q.push(make_pair(newPos, curDay + 1));
				mapp[newPos[0]][newPos[1]][newPos[2]] = 1;
				remainTomatoes --;
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

	cin >> x >> y >> z;

	for ( int k = 0; k < z; k++ ) {
		vector<vector<int>> tempBoard;
		for ( int i = 0; i < y; i++ ) {
			vector<int> tempRow;
			for ( int j = 0; j < x; j++ ) {
				cin >> temp;
				tempRow.push_back(temp);
				if ( temp == 0 ) remainTomatoes++;
				if ( temp == 1 ) {
					q.push(make_pair(vector<int> {k, i , j}, 0));
				}
			}
			tempBoard.push_back(tempRow);
		}
		mapp.push_back(tempBoard);
	}

	enripenTomatoes();

	cout << (remainTomatoes ? -1 : maxi) << endl;

    return 0;
}
