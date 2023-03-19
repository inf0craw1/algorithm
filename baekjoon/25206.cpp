#include <iostream>
#include <map>

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

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	string str, grade;
	double credit, totalGrade = 0, creditSum = 0;
	map<string, double> gradeMap = {
		{"A+", 4.5},
		{"A0", 4.0},
		{"B+", 3.5},
		{"B0", 3.0},
		{"C+", 2.5},
		{"C0", 2.0},
		{"D+", 1.5},
		{"D0", 1.0},
		{"F", 0.0},
	};

	while(cin >> str) {
		cin >> credit >> grade;

		if ( grade ==  "P" ) {
			continue;
		}

		auto pos = gradeMap.find(grade);
		if ( pos == gradeMap.end() ) return -1;

		totalGrade += credit * pos->second;
		creditSum += credit;

	}
	
	cout << totalGrade / creditSum << endl;

    return 0;
}
