#include <iostream>
#include <vector>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define vii vector<vector<int>>
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
int height, width, x, y, commands, curCommand, temp;
pii curPos;
vector<int> dice = {0, 1, 2, 3, 4, 5}, diceValue = {0, 0, 0, 0, 0, 0};
vector<int> vertical = {0, 2, 4, 5}, horizontal = {1, 2, 3, 5};
vector<int> bottomSide = {4, 3, 5, 1, 0, 2};
vector<pii> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vii mapp;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void RotateDice(int dir) {
	vector<int> curDir = (dir <= 2) ? horizontal : vertical;
	int temp;

	if ( dir == 1 || dir == 4 ) {
		temp = dice[curDir[3]];
		for ( int i = 3; i > 0; i-- ) {
			dice[curDir[i]] = dice[curDir[i-1]];
		}
		dice[curDir[0]] = temp;
	} else {
		temp = dice[curDir[0]];
		for ( int i = 0; i < 3; i++ ) {
			dice[curDir[i]] = dice[curDir[i+1]];
		}
		dice[curDir[3]] = temp;
	}
}
bool MovePosition(int command) {
	pii newPos = make_pair(curPos.fi + directions[command - 1].fi, curPos.se + directions[command - 1].se);

	if ( newPos.fi < 0 || newPos.fi >= height || newPos.se < 0 || newPos.se >= width ) return 0;
	curPos = newPos;
	return 1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> height >> width >> y >> x >> commands;

	curPos = make_pair(y, x);

	for ( int i = 0; i < height; i++ ) {
		vector<int> tempRow;
		for ( int j = 0; j < width; j++ ) {
			cin >> temp;
			tempRow.push_back(temp);
		}
		mapp.push_back(tempRow);
	}

	for ( int i = 0; i < commands; i++ ) {
		cin >> curCommand;

		if ( !MovePosition(curCommand) ) continue;

		RotateDice(curCommand);

		if ( mapp[curPos.fi][curPos.se] == 0 ) {
			mapp[curPos.fi][curPos.se] = diceValue[bottomSide[dice[2]]];
		} else {
			diceValue[bottomSide[dice[2]]] = mapp[curPos.fi][curPos.se];
			mapp[curPos.fi][curPos.se] = 0;
		}
		cout << diceValue[dice[2]] << endl;
	}

    return 0;
}
