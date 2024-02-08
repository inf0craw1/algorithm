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
int rotation, temp;
vector<vector<int>> gears;
vector<pii> gearPositions = {{6, 2}, {6, 2}, {6, 2}, {6, 2}};

/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSameType(int t1, int t2) {
	return ( t1 - t2 == 0 ? 1 : 0 );
}
bool CheckChainingRotatable(int curGear, int chainingDirection ) {
	if ( chainingDirection == -1 && curGear == 0  ) return 0;
	if ( chainingDirection == 1 && curGear == 3 ) return 0;

	int curGearType, objGearType;

	if ( chainingDirection == 1 ) {
		curGearType = gears[curGear][gearPositions[curGear].se];
		objGearType = gears[curGear+1][gearPositions[curGear+1].fi];
	} else {
		curGearType = gears[curGear][gearPositions[curGear].fi];
		objGearType = gears[curGear-1][gearPositions[curGear-1].se];
	}

	if ( IsSameType(curGearType, objGearType) ) return 0;
	return 1;
}
void RotateGear(int curGear, int direction) {
	if ( direction == -1 ) {
		gearPositions[curGear].fi = (gearPositions[curGear].fi + 1) % 8;
		gearPositions[curGear].se = (gearPositions[curGear].fi + 4) % 8;
		return;
	}
	if ( gearPositions[curGear].fi == 0 ) {
		gearPositions[curGear].fi = 7;
	} else {
		gearPositions[curGear].fi --;
	}
	gearPositions[curGear].se = (gearPositions[curGear].fi + 4) % 8;
}
void PrintGears() {
	for ( int i = 0, pos = gearPositions[i].fi; i < 4; i++, pos %= 8 ) {
		for ( int j = 0, pos = gearPositions[i].fi; j < 8; j++, pos %= 8 ) {
			cout << gears[i][pos++];
		}
		cout << endl;
	}
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);


	for ( int i = 0; i < 4; i++ ) {
		vector<int> tempRow;
		string tempStr;
		cin >> tempStr;
		for ( auto t: tempStr ) {
			tempRow.push_back(t-'0');
		}
		gears.push_back(tempRow);
	}

	cin >> rotation;

	for ( int i = 0; i < rotation; i++ ) {
		int objGear, direction;

		cin >> objGear >> direction;
		
		objGear --;


		int leftwardGear = objGear, rightwardGear = objGear;
		vector<pii> needRotationGears;
		needRotationGears.push_back(make_pair(objGear, direction));
		
		int tempRotateDirection = direction;
		while ( CheckChainingRotatable(leftwardGear, -1) ) {
			tempRotateDirection *= -1;
			needRotationGears.push_back(make_pair(--leftwardGear, tempRotateDirection));
		}
		tempRotateDirection = direction;
		while ( CheckChainingRotatable(rightwardGear, 1) ) {
			tempRotateDirection *= -1;
			needRotationGears.push_back(make_pair(++rightwardGear, tempRotateDirection));
		}
		for ( auto n: needRotationGears ) {
			RotateGear(n.fi, n.se);
		}
	}

	int res = 0;
	for ( int i = 0, score = 1; i < 4; i++, score *= 2 ) {
		int topPositionIndex = (gearPositions[i].fi + 2) % 8;
		if ( gears[i][topPositionIndex] == 1 ) res += score;
	}
	cout << res << endl;

    return 0;
}
