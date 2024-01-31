#include <iostream>
#include <vector>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int, int>

#ifdef local
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/* - global variables ---------------------------- */
int width, height, rotation, temp; 
vector<vector<int>> mapp;
/* ----------------------------------------------- */

/* - functions ----------------------------------- */
void rotatepeel(pii spos, pii epos) {
	int i = spos.fi, j = spos.se;
	vector<int> peel;

	for ( ; j < epos.se; j++ ) {
		peel.push_back(mapp[i][j]);
	}
	for ( ; i < epos.fi; i++ ) {
		peel.push_back(mapp[i][j]);
	}
	for ( ; j > spos.se; j-- ) {
		peel.push_back(mapp[i][j]);
	}
	for ( ; i > spos.fi; i-- ) {
		peel.push_back(mapp[i][j]);
	}
	
	i = spos.fi;
	j = spos.se;
	int peelsize = peel.size();
	int startpoint = rotation % peelsize;

	for ( ; j < epos.se; j++, startpoint %= peelsize ) {
		mapp[i][j] = peel[startpoint++];
	}
	for ( ; i < epos.fi; i++, startpoint %= peelsize ) {
		mapp[i][j] = peel[startpoint++];
	}
	for ( ; j > spos.se; j--, startpoint %= peelsize ) {
		mapp[i][j] = peel[startpoint++];
	}
	for ( ; i > spos.fi; i--, startpoint %= peelsize ) {
		mapp[i][j] = peel[startpoint++];
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
		vector<int> temprow;
		for ( int j = 0; j < width; j++ ) {
			cin >> temp;
			temprow.push_back(temp);
		}
		mapp.push_back(temprow);
	}

	pii spos = make_pair(0, 0);
	pii epos = make_pair(height - 1, width - 1);
	while ( spos.fi < epos.fi && spos.se < epos.se ) {
		rotatepeel(spos, epos);
		spos.fi ++;
		spos.se ++;
		epos.fi --;
		epos.se --;
	}
	for ( auto row: mapp ) {
		for ( auto r: row ) {
			cout << r << ' ';
		}
		cout << endl;
	}

    return 0;
}
