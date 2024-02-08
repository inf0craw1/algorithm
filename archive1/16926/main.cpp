#include <iostream>
#include <vector>

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
int width, height, rotation, temp; 
vector<vector<int>> mapp;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void RotatePeel(pii sPos, pii ePos) {
	int i = sPos.fi, j = sPos.se;
	vector<int> peel;

	for ( ; j < ePos.se; j++ ) {
		peel.push_back(mapp[i][j]);
	}
	for ( ; i < ePos.fi; i++ ) {
		peel.push_back(mapp[i][j]);
	}
	for ( ; j > sPos.se; j-- ) {
		peel.push_back(mapp[i][j]);
	}
	for ( ; i > sPos.fi; i-- ) {
		peel.push_back(mapp[i][j]);
	}
	
	i = sPos.fi;
	j = sPos.se;
	int peelSize = peel.size();
	int startPoint = rotation % peelSize;

	for ( ; j < ePos.se; j++, startPoint %= peelSize ) {
		mapp[i][j] = peel[startPoint++];
	}
	for ( ; i < ePos.fi; i++, startPoint %= peelSize ) {
		mapp[i][j] = peel[startPoint++];
	}
	for ( ; j > sPos.se; j--, startPoint %= peelSize ) {
		mapp[i][j] = peel[startPoint++];
	}
	for ( ; i > sPos.fi; i--, startPoint %= peelSize ) {
		mapp[i][j] = peel[startPoint++];
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> height >> width >> rotation;

	for ( int i = 0; i < height; i++ ) {
		vector<int> tempRow;
		for ( int j = 0; j < width; j++ ) {
			cin >> temp;
			tempRow.push_back(temp);
		}
		mapp.push_back(tempRow);
	}

	pii sPos = make_pair(0, 0);
	pii ePos = make_pair(height - 1, width - 1);
	while ( sPos.fi < ePos.fi && sPos.se < ePos.se ) {
		RotatePeel(sPos, ePos);
		sPos.fi ++;
		sPos.se ++;
		ePos.fi --;
		ePos.se --;
	}
	for ( auto row: mapp ) {
		for ( auto r: row ) {
			cout << r << ' ';
		}
		cout << endl;
	}

    return 0;
}
