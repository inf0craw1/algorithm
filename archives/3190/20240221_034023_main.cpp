#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef unsigned long long ull;

/* - GLOBAL VARIABLES ---------------------------- */
vector<vi> mapp;
deque<pi> body;
vector<pi> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<pair<int, char>> commands;
pi curHeadPos = make_pair(1, 1);
int mapSize, apples, nextCommand = 0, curDirection = 1;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pi pos) {
	if ( pos.fi <= 0 || pos.fi > mapSize || pos.se <= 0 || pos.se > mapSize ) return 0;
	if ( mapp[pos.fi][pos.se] == 2 ) return 0;
	return 1;
}
void ChangeDirection(char cmd) {
	if ( cmd == 'L' ) curDirection --;
	else curDirection ++;
	if ( curDirection == 4 ) curDirection = 0;
	if ( curDirection == -1 ) curDirection = 3;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> mapSize >> apples;
	mapp.resize(mapSize+1, vi(mapSize+1, 0));
	body.push_front(make_pair(1, 1));
	mapp[1][1] = 2;
	for ( int i = 0; i < apples; i++ ) {
		int y, x;
		cin >> y >> x;
		mapp[y][x] = 1;
	}
	int numberOfCommands; cin >> numberOfCommands;

	for ( int i = 0; i < numberOfCommands; i++ ) {
		int time; cin >> time;
		char type; cin >> type;
		commands.push_back(make_pair(time, type));
	}

	for ( int i = 1;; i++ ) {
		curHeadPos = make_pair(curHeadPos.fi + directions[curDirection].fi, curHeadPos.se + directions[curDirection].se);
		if ( !IsSafe(curHeadPos) ) {
			cout << i << endl;
			return 0;
		}
		body.push_front(curHeadPos);
		if ( mapp[curHeadPos.fi][curHeadPos.se] == 0 ) {
			pi tailPos = body.back();
			mapp[tailPos.fi][tailPos.se] = 0;
			body.pop_back();
		}
		mapp[curHeadPos.fi][curHeadPos.se] = 2;
		if ( nextCommand < numberOfCommands && i == commands[nextCommand].fi ) {
			ChangeDirection(commands[nextCommand].se);
			nextCommand ++;
		}
	}

    return 0;
}
