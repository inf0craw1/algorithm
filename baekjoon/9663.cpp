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
int num, cnt = 0; 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

int isSafe(int row, int col) {
	if ( row < 0 || col < 0 || row >= num || col >= num ) return 0;
	return 1;
}

vector<vector<int>> blockMap(int row, int col, vector<vector<int>> m) {
	for ( int i = 0; i < num - row; i++ ) {
		m[row+i][col] = 1;
		if ( isSafe(row+i, col+i) ) {
			m[row+i][col+i] = 1;
		}
		if ( isSafe(row+i, col-i) ) {
			m[row+i][col-i] = 1;
		}
	}

	return m;
}

void placeQueen(int head, vector<vector<int>> m) {

	if ( head == num ) {
		cnt++;
		return;
	}

	int chk = 0;
	for ( int i = 0; i < num; i++ ) {
		if ( !m[head][i] ) {
			chk = 1;
			vector<vector<int>> newMap = m;
			newMap = blockMap(head, i, m);
			placeQueen(head+1, newMap);
		}
	}
	if (!chk) return;

	return;
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> num;

	vector<vector<int>> empty(num, vector<int> (num, 0));
	
	placeQueen(0, empty);
	
	cout << cnt << endl;

    return 0;
}
