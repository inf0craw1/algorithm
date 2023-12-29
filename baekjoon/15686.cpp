#include <iostream>
#include <vector>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/* - GLOBAL VARIABLES ---------------------------- */

int n, m, mini = 2e9;
vector<pair<int, int>> houses, chickens;
vector<vector<int>> mapp, temp_mapp;
vector<vector<int>> directions{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

int isSafe(int i, int j) {
	if ( i < 0 || j < 0 || i >= n || j >= n ) {
		return 0;
	}
	return 1;
}
void checkChickenDistance(int distance, int i, int j) {
	if ( temp_mapp[i][j] < distance ) return;
	temp_mapp[i][j] = distance;

	for ( int k = 0; k < 4; k++ ) {
		int newI = i + directions[k][0];
		int newJ = j + directions[k][1];
		if ( isSafe(newI, newJ) && temp_mapp[newI][newJ] >= distance + 1 ) {
			checkChickenDistance(distance + 1, newI, newJ);
		}
	}
}

void getChickenCombination(vector<int> cmbn) {
	int size = cmbn.size();

	if ( size == m ) {
		temp_mapp = mapp;
		
		for ( auto c: cmbn ) {
			checkChickenDistance(0, chickens[c].fi, chickens[c].se);
		}

		int sum = 0;
		for ( auto house: houses ) {
			sum += temp_mapp[house.fi][house.se];
		}
		mini = min(mini, sum);
		return;
	}
	
	for ( int i = size ? cmbn[size - 1] + 1 : 0; i < chickens.size(); i++ ) {
		vector<int> newVec = cmbn;
		newVec.push_back(i);
		getChickenCombination(newVec);
	}
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int temp;
	vector<int> empty, temp_row;
	cin >> n >> m;

	mapp.resize(n, vector<int> (n, 2e9));

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			cin >> temp;
			if ( temp == 1 ) {
				houses.push_back(make_pair(i, j));
				continue;
			}
			if ( temp == 2 ) {
				chickens.push_back(make_pair(i, j));
			}
		}
	}

	getChickenCombination(empty);

	cout << mini << endl;

    return 0;
}
