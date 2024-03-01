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
bool foundAnswer = false;
vector<vector<int>> mapp, rowChk, colChk;
vector<vector<vector<int>>> squareChk;
vector<pi> blanks;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void SolveSudoku(int curBlank) {
	if ( curBlank == blanks.size()) {
		foundAnswer = true;
		return;
	}
	vector<int> possibleNums;
	pi curPos = blanks[curBlank];
	
	for ( int i = 1; i < 10; i++ ) {
		if ( rowChk[curPos.fi][i] + colChk[curPos.se][i] + squareChk[curPos.fi/3][curPos.se/3][i] == 0 ) {
			possibleNums.push_back(i);
		}
	}

	if ( possibleNums.empty() ) return;

	for ( auto p: possibleNums ) {
		rowChk[curPos.fi][p] = 1;
		colChk[curPos.se][p] = 1;
		squareChk[curPos.fi/3][curPos.se/3][p] = 1; 
		mapp[curPos.fi][curPos.se] = p;
		SolveSudoku(curBlank+1);
		if ( foundAnswer ) return;
		rowChk[curPos.fi][p] = 0;
		colChk[curPos.se][p] = 0;
		squareChk[curPos.fi/3][curPos.se/3][p] = 0;
		mapp[curPos.fi][curPos.se] = 0;
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	rowChk.resize(11, vector<int> (11, 0));
	colChk.resize(11, vector<int> (11, 0));
	squareChk.resize(3, vector<vector<int>> (3, vector<int> (11, 0)));


	for ( int i = 0; i < 9; i++ ) {
		int tempNum; cin >> tempNum;
		int digit = 1e8;
		vector<int> tempRow(9, 0);
		for ( int j = 0; j < 9; j++ ) {
			int temp = tempNum / digit % 10; 

			digit /= 10;

			tempRow[j] = temp;
			if ( temp == 0 ) {
				blanks.push_back(make_pair(i, j));
				continue;
			}
			rowChk[i][temp] = 1;
			colChk[j][temp] = 1;
			squareChk[i/3][j/3][temp] = 1;
		}
		mapp.push_back(tempRow);
	}

	SolveSudoku(0);

	for ( auto row: mapp ) {
		for ( auto r: row ) {
			cout << r;
		}
		cout << endl;
	}
    return 0;
}
