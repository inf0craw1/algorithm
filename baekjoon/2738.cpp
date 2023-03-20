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
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	vector<vector<int>> matrix1, matrix2;
	int x, y, temp;

	cin >> y >> x;

	for ( int i = 0; i < y; i++ ) {
		vector<int> row;
		for ( int j = 0; j < x; j++ ) {
			cin >> temp;
			row.push_back(temp);
		}
		matrix1.push_back(row);
	}
	for ( int i = 0; i < y; i++ ) {
		vector<int> row;
		for ( int j = 0; j < x; j++ ) {
			cin >> temp;
			row.push_back(temp);
		}
		matrix2.push_back(row);
	}
	
	for ( int i = 0; i < y; i++ ) {
		for ( int j = 0; j < x; j++ ) {
			cout << matrix1[i][j] + matrix2[i][j] << ' ';
		}
		cout << endl;
	}

    return 0;
}
