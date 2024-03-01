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
int mapSize, maxi1 = 0, maxi2 = 0;
vector<vi> bannedMap;
map<int, unordered_set<int>> diagonal1;
unordered_set<int> diagonal2;
/* ----------------------------------------------- */
/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pi pos) {
	if ( pos.fi < 0 || pos.fi >= mapSize || pos.se < 0 || pos.se >= mapSize ) return 0;
	return 1;
}
void PlaceBishop(int curDiagonal, int count) {
	if ( curDiagonal > 2*(mapSize-1) ) {
		if ( curDiagonal % 2 == 0 ) {
			maxi1 = max(maxi1, count);
			return;
		}
		maxi2 = max(maxi2, count);
		return;
	}

	auto foundDiagonal = diagonal1.find(curDiagonal);

	for ( auto d2: foundDiagonal->se ) {
		if ( diagonal2.find(d2) != diagonal2.end() ) {
			diagonal2.erase(d2);
			PlaceBishop(curDiagonal+2, count + 1);
			diagonal2.insert(d2);
		}
	}

	PlaceBishop(curDiagonal+2, count);
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> mapSize;

	for ( int i = 0; i < mapSize; i++ ) {
		vi tempRow;
		for  (int j = 0; j < mapSize; j++) {
			int temp; cin >> temp;
			tempRow.push_back(temp);
			if (temp == 1) {
				auto foundD = diagonal1.find(i+j);
				if ( foundD == diagonal1.end() ) {
					diagonal1.insert({i+j, {i-j}});
				} else {
					foundD->se.insert(i-j);
				}
				diagonal2.insert(i-j);
			}
		}
		bannedMap.push_back(tempRow);
	}
	PlaceBishop(0, 0);
	PlaceBishop(1, 0);

	cout << maxi1 + maxi2 << endl;

    return 0;
}
