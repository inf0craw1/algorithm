#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>

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
int n, rangeS, rangeE, temp, openBorderNum, day = 0; 
vector<int> populationAvg;
vector<vector<int>> mapp, borderMap;
vector<pii> directions = { { -1, 0 }, {0, -1}, {0, 1}, {1, 0} };
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pii pos) {
	if ( pos.fi < 0 || pos.se < 0 || pos.fi >= n || pos.se >= n ) return 0;
	return 1;
}
void SetOpenBorders(pii pos, int openBorderNum) {
	queue<pii> q;
	q.push(pos);
	int openBorderSum = 0, openBorderCnt = 0;

	while ( q.size() ) {
		pii curPos = q.front();
		q.pop();
		if ( borderMap[curPos.fi][curPos.se] ) continue;
		borderMap[curPos.fi][curPos.se] = openBorderNum;
		openBorderSum += mapp[curPos.fi][curPos.se];
		openBorderCnt ++;
		for ( auto d: directions ) {
			pii newPos = make_pair(curPos.fi + d.fi, curPos.se + d.se);
			if ( !IsSafe(newPos) ) continue;
			if ( borderMap[newPos.fi][newPos.se] != 0 ) continue;
			int diff = abs(mapp[curPos.fi][curPos.se] - mapp[newPos.fi][newPos.se]);
			if ( diff < rangeS || diff > rangeE ) continue;
			q.push(newPos);
		}
	}
	populationAvg.push_back(openBorderSum / openBorderCnt);
}
int ChkOpenBorders() {
	openBorderNum = 0;
	borderMap.clear();
	borderMap.resize(n, vector<int> (n, 0));
	populationAvg.clear();
	populationAvg.push_back(0);
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			if ( borderMap[i][j] != 0 ) continue;
			for ( auto d: directions ) {
				pii newPos = make_pair(i + d.fi, j + d.se);
				if ( !IsSafe(newPos) ) continue;
				int diff = abs(mapp[i][j] - mapp[newPos.fi][newPos.se]);
				if ( diff < rangeS || diff > rangeE) continue;
				SetOpenBorders(newPos, ++openBorderNum);
				break;
			}
		}
	}
	
	return openBorderNum;
}
void movePopulation(int openBorderNum) {
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			if ( borderMap[i][j] ) {
				mapp[i][j] = populationAvg[borderMap[i][j]];
			}
		}
	}

}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n >> rangeS >> rangeE;
	for ( int i = 0; i < n; i++ ) {
		vector<int> tempRow;
		for ( int j = 0; j < n; j++ ) {
			cin >> temp;
			tempRow.push_back(temp);
		}
		mapp.push_back(tempRow);
	}

	while ( ChkOpenBorders() ) {
		movePopulation(openBorderNum);
		day ++;

	}
	cout << day << endl;

    return 0;
}
