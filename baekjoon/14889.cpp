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

int num, mini = 2e9, numberOfCases, cnt = 0;
vector<vector<int>> stats = {{0}};
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int getCount(int n) {
	int res = 1;
	int half = n / 2;
	for ( int i = half + 1; i <= n; i++) {
		res *= i;
	}
	for ( int i = 2; i <= half; i++ ) {
		res /= i;
	}
	
	return res/2;
}

int getTeamScore(vector<int> teamArr) {
	int size = teamArr.size();
	int teamScore = 0;

	for ( int i = 0; i < size; i++ ) {
		for ( int j = i+1; j < size; j++ ) {
			teamScore += stats[teamArr[i]][teamArr[j]];
			teamScore += stats[teamArr[j]][teamArr[i]];
		}
	}

	return teamScore;
}

void selectTeam(vector<int> teamArr) {
	if ( numberOfCases <= cnt ) return;
	if ( teamArr.size() ) {
		if ( teamArr.size() == num / 2 ) {
			cnt ++;
			vector<int> otherTeamArr;
			for ( int i = 1; i <= num; i++ ) {
				int chk = 0;
				for ( auto t: teamArr ) {
					if ( t == i ) {
						chk = 1;
						break;
					}
				}
				if ( !chk ) {
					otherTeamArr.push_back(i);
				}
			}
			int teamScore = getTeamScore(teamArr);
			int otherTeamScore = getTeamScore(otherTeamArr);
			int diff = teamScore - otherTeamScore;
			if ( diff < 0 ) diff *= -1;

			mini = min(mini, diff);

			return;
		}
	}

	for ( int i = (teamArr.size() ? teamArr[teamArr.size() - 1] + 1 : 1); i <= num; i++ ) {
		vector<int> newTeamArr = teamArr;
		newTeamArr.push_back(i);
		selectTeam(newTeamArr);
	}
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int temp;

	cin >> num;

	numberOfCases = getCount(num);

	for ( int i = 0; i < num; i++ ) {
		vector<int> temp_stats = {0};
		for ( int j = 0; j < num; j++ ) {
			cin >> temp;

			temp_stats.push_back(temp);
		}
		stats.push_back(temp_stats);
	}

	vector<int> empty_vector;
	selectTeam(empty_vector);

	cout << mini << endl;

    return 0;
}
