#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

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
int height, width;
vector<vector<int>> mapp;
vector<vector<pii>> stepMap;
queue<pii> q;
vector<pii> directions = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSafe(pii pos) {
	if ( pos.fi < 0 || pos.fi >= height || pos.se < 0 || pos.se >= width ) return 0;
	return 1;
}
pii IsAbleToStep(pii curPos, pii newPos) {
	int curType = mapp[curPos.fi][curPos.se];
	int newType = mapp[newPos.fi][newPos.se];
	pii curStep = stepMap[curPos.fi][curPos.se];
	pii newStep = stepMap[newPos.fi][newPos.se];

	if ( curType == 0 && newType == 0 ) {
		pii makeStep;
		makeStep.fi = curStep.fi != 0 ? curStep.fi + 1 : newStep.fi;
		makeStep.se = curStep.se != 0 ? curStep.se + 1 : newStep.se;
		if ( (newStep.fi == 0 && makeStep.fi != 0) || (newStep.se == 0 && makeStep.se != 0) ) return makeStep;
		if ( makeStep.fi < newStep.fi || makeStep.se < newStep.se ) return makeStep;
		return make_pair(-1, -1);
	}
	if ( newType == 1 ) {
		if ( curStep.se == 0 ) return make_pair(-1, -1);
		if ( newStep.fi != 0 && newStep.fi <= curStep.se + 1 ) return make_pair(-1, -1);
		pii makeStep = make_pair( curStep.se + 1, newStep.se );
		return makeStep;
	}
	if ( newType == 0 ) {
		if ( newStep.fi != 0 && newStep.fi <= curStep.fi + 1 ) return make_pair(-1, -1);
		pii makeStep = make_pair( curStep.fi + 1, newStep.se );
		return makeStep;
	}
	return make_pair(-1, -1);
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> height >> width;

	stepMap.resize(height, vector<pii> (width, make_pair(0, 0)));
	stepMap[0][0].se = 1;

	for ( int i = 0; i < height; i++ ) {
		vector<int> tempRow;
		string tempString;
		cin >> tempString;
		for ( auto t: tempString ) {
			tempRow.push_back(t - '0');
		}
		mapp.push_back(tempRow);
	}

	q.push(make_pair(0, 0));

	while ( q.size() ) {
		pii curPos = q.front();
		q.pop();

		if ( curPos.fi == height - 1 && curPos.se == width - 1 ) break;

		for ( auto d: directions ) {
			pii newPos = make_pair( curPos.fi + d.fi, curPos.se + d.se);
			if ( !IsSafe(newPos) ) continue;
			pii res = IsAbleToStep(curPos, newPos);
			if ( res.fi == -1 ) continue;
			stepMap[newPos.fi][newPos.se] = res;
			q.push(newPos);
		}
	}

	int mini = 2e9;
	
	pii objStep = stepMap[height - 1][width - 1];
	if ( objStep.fi == 0 && objStep.se == 0 ) {
		cout << -1 << endl;
		return 0;
	}
	if ( objStep.fi != 0 ) mini = min(mini, objStep.fi);
	if ( objStep.se != 0 ) mini = min(mini, objStep.se);

	cout << mini << endl;

    return 0;
}
