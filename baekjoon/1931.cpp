#include <iostream>
#include <algorithm>
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
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int comp(pair<int, int> a, pair<int, int> b) {
	if ( a.se == b.se ) return a.fi < b.fi;
	return a.se < b.se;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int num, startTime, endTime, lastEndTime = -1, fixedMeetingCount = 0;
	vector<pair<int, int>> meetings;

	cin >> num;
	
	for ( int i = 0; i < num; i++ ) {
		cin >> startTime >> endTime;
		meetings.push_back(make_pair(startTime, endTime));
	}

	sort(meetings.begin(), meetings.end(), comp);

	for ( auto m: meetings ) {
		if ( m.fi >= lastEndTime ) {
			lastEndTime = m.se;
			fixedMeetingCount++;
		}
	}

	cout << fixedMeetingCount << endl;
    return 0;
}
