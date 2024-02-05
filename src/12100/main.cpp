#include <iostream>
#include <vector>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
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
int n, temp, maxi = -1;
vvi mapp, iterData;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
vvi PushAndCombineBlock(vvi mapp, int dir) {
	if ( dir == 0 ) {
		for ( int j = 0; j < n; j++ ) {
			int firstZeroIdx = -1, lastNumIdx = -1;
			for ( int i = 0; i < n; i++ ) {
					if ( mapp[i][j] == 0 ) {
					if ( firstZeroIdx == -1 ) firstZeroIdx = i;
					continue;
				}
				if ( lastNumIdx != -1 && mapp[lastNumIdx][j] == mapp[i][j] ) {
					mapp[lastNumIdx][j] *= 2;
					mapp[i][j] = 0;
					firstZeroIdx = lastNumIdx + 1;
					lastNumIdx = -1;
					continue;
				}
				if ( firstZeroIdx != -1 ) {
					mapp[firstZeroIdx][j] = mapp[i][j];
					mapp[i][j] = 0;
					lastNumIdx = firstZeroIdx;
					firstZeroIdx ++;
					continue;
				}
				lastNumIdx = i;
			}
		}
	}
	else if ( dir == 1 ) {
		for ( int i = 0; i < n; i++ ) {
			int firstZeroIdx = -1, lastNumIdx = -1;
			for ( int j = 0; j < n; j++ ) {
					if ( mapp[i][j] == 0 ) {
					if ( firstZeroIdx == -1 ) firstZeroIdx = j;
					continue;
				}
				if ( lastNumIdx != -1 && mapp[i][lastNumIdx] == mapp[i][j] ) {
					mapp[i][lastNumIdx] *= 2;
					mapp[i][j] = 0;
					firstZeroIdx = lastNumIdx + 1;
					lastNumIdx = -1;
					continue;
				}
				if ( firstZeroIdx != -1 ) {
					mapp[i][firstZeroIdx] = mapp[i][j];
					mapp[i][j] = 0;
					lastNumIdx = firstZeroIdx;
					firstZeroIdx ++;
					continue;
				}
				lastNumIdx = j;
			}
		}
	}
	else if ( dir == 2 ) {
		for ( int i = n-1; i >= 0; i-- ) {
			int firstZeroIdx = -1, lastNumIdx = -1;
			for ( int j = n-1; j >= 0; j-- ) {
					if ( mapp[i][j] == 0 ) {
					if ( firstZeroIdx == -1 ) firstZeroIdx = j;
					continue;
				}
				if ( lastNumIdx != -1 && mapp[i][lastNumIdx] == mapp[i][j] ) {
					mapp[i][lastNumIdx] *= 2;
					mapp[i][j] = 0;
					firstZeroIdx = lastNumIdx - 1;
					lastNumIdx = -1;
					continue;
				}
				if ( firstZeroIdx != -1 ) {
					mapp[i][firstZeroIdx] = mapp[i][j];
					mapp[i][j] = 0;
					lastNumIdx = firstZeroIdx;
					firstZeroIdx --;
					continue;
				}
				lastNumIdx = j;
			}
		}
	}
	else if ( dir == 3 ) {
		for ( int j = n-1; j >= 0; j-- ) {
			int firstZeroIdx = -1, lastNumIdx = -1;
			for ( int i = n-1; i >= 0; i-- ) {
					if ( mapp[i][j] == 0 ) {
					if ( firstZeroIdx == -1 ) firstZeroIdx = i;
					continue;
				}
				if ( lastNumIdx != -1 && mapp[lastNumIdx][j] == mapp[i][j] ) {
					mapp[lastNumIdx][j] *= 2;
					mapp[i][j] = 0;
					firstZeroIdx = lastNumIdx - 1;
					lastNumIdx = -1;
					continue;
				}
				if ( firstZeroIdx != -1 ) {
					mapp[firstZeroIdx][j] = mapp[i][j];
					mapp[i][j] = 0;
					lastNumIdx = firstZeroIdx;
					firstZeroIdx --;
					continue;
				}
				lastNumIdx = i;
			}
		}
	}
	return mapp;
}

void CombinationMove(vvi mapp, int cnt) {
	if ( cnt >= 5 ) {
		for ( auto row: mapp ) {
			for ( auto r: row ) {
				maxi = max(maxi, r);
			}
		}
		return;
	}
	for ( int i = 0; i < 4; i++ ) {
		vvi newMapp = PushAndCombineBlock(mapp, i);
		CombinationMove(newMapp, cnt + 1);
	}
}
void PrintMap() {
	cout << "--------------------" << endl;
	for ( auto row: mapp ) {
		for ( auto r: row ) {
			cout << r << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		vector<int> tempRow;
		for ( int j = 0; j < n; j++ ) {
			cin >> temp;
			tempRow.push_back(temp);
		}
		mapp.push_back(tempRow);
	}

	CombinationMove(mapp, 0);

	cout << maxi << endl;

    return 0;
}
