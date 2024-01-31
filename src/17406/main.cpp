#include <iostream>
#include <vector>
#include <set>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int, int>
#define vvi vector<vector<int>> 

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/* - GLOBAL VARIABLES ---------------------------- */
int width, height, operation, temp, mini = 2e9;
vvi mapp;
vector<pair<pii, int>> operations;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int GetMinOfRow(vvi m) {
	for ( int j = 1; j < width; j++ ) {
		for ( int i = 0; i < height; i++ ) {
			m[i][j] += m[i][j-1];
		}
	}
	int mini = 2e9;
	for ( int i = 0; i < height; i++ ) {
		mini = min(mini, m[i][width-1]);
	}
	return mini;
}

vvi RotatePeel(vvi m, pii sPos, pii ePos) {
	int topLeft = m[sPos.fi][sPos.se];
	int i = sPos.fi, j = sPos.se;

	for ( ; i < ePos.fi; i++ ) {
		m[i][j] = m[i+1][j];
	}
	for ( ; j < ePos.se; j++ ) {
		m[i][j] = m[i][j+1];
	}
	for ( ; i > sPos.fi; i-- ) {
		m[i][j] = m[i-1][j];
	}
	for ( ; j > sPos.se; j-- ) {
		m[i][j] = m[i][j-1];
	}
	m[sPos.fi][sPos.se+1] = topLeft;
	return m;
}

vvi RotateAll(vvi m, int op) {
	pair<pii, int> curOperation = operations[op];
	pii centerPos = curOperation.fi;
	int range = curOperation.se;

	for ( int i = 1; i <= range; i++ ) {
		m = RotatePeel(m, make_pair(centerPos.fi - i, centerPos.se - i), make_pair(centerPos.fi + i, centerPos.se + i));
	}
	return m;
}

void MakeOperationCombination(vvi m, set<int> remainOperations, vector<int> ops) {
	if ( remainOperations.empty() ) {
		mini = min(mini, GetMinOfRow(m));
		return;
	}
	for ( auto r: remainOperations ) {
		vvi newMap = RotateAll(m, r);
		set<int> newRemainOperations = remainOperations;
		newRemainOperations.erase(r);
		vector<int> operationTrace = ops;
		operationTrace.push_back(r);
		MakeOperationCombination(newMap, newRemainOperations, operationTrace);
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> height >> width >> operation;
	for ( int i = 0; i < height; i++ ) {
		vector<int> tempRow;
		for ( int j = 0; j < width; j++ ) {
			cin >> temp;
			tempRow.push_back(temp);
		}
		mapp.push_back(tempRow);
	}
	set<int> allOperations;
	for ( int i = 0; i < operation; i++ ) {
		int row, col, range;
		cin >> row >> col >> range;
		operations.push_back(make_pair(make_pair(row-1, col-1), range));
		allOperations.insert(i);
	}

	MakeOperationCombination(mapp, allOperations, {});

	cout << mini << endl;

    return 0;
}
