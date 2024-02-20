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
int row, col, timeLimit;
vector<vector<int>> mapp;
vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
pair<int, int> gramPos;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pair<int, int> pos) {
	if ( pos.fi < 0 || pos.fi >= row || pos.se < 0 || pos.se >= col ) return 0;
	return 1;
}
void GoAll() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	mapp[0][0] = 0;

	while ( q.size() ) {
		pair<int, int> curPos = q.front();
		int curTime = mapp[curPos.fi][curPos.se];
		q.pop();
		for ( auto d: directions ) {
			pair<int, int> newPos = make_pair(curPos.fi + d.fi, curPos.se + d.se);
			if ( !IsSafe(newPos) || mapp[newPos.fi][newPos.se] <= curTime + 1 ) continue;
			mapp[newPos.fi][newPos.se] = curTime + 1;
			q.push(newPos);
		}
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> row >> col >> timeLimit;
	for ( int i = 0; i < row; i++ ) {
		vector<int> tempRow;
		for ( int j = 0; j < col; j++ ) {
			int temp; cin >> temp;

			if ( temp == 1 ) {
				tempRow.push_back(-1);
				continue;
			}
			tempRow.push_back(2e9);
			if ( temp == 2 ) gramPos = make_pair(i, j);
		}
		mapp.push_back(tempRow);
	}

	GoAll();

	int gramTime = mapp[gramPos.fi][gramPos.se] + (row-1 - gramPos.fi) + (col-1 - gramPos.se);
	int lastTime = mapp[row-1][col-1];
	int mini = min(gramTime, lastTime);

	if ( mini > timeLimit ) {
		cout << "Fail" << endl;
		return 0;
	}
	cout << mini << endl;

    return 0;
}
