#include <iostream>

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

int arr[101] = {0};
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

void rotate(int* arr, int begin, int end) {
	int temp = arr[begin];

	for ( int i = begin; i < end; i++ ) {
		arr[i] = arr[i + 1];
	}

	arr[end] = temp;
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n, m;
	int begin, mid, end;

	for ( int i = 1; i < 101; i++ ) {
		arr[i] = i;
	}

	cin >> n >> m;

	for ( int i = 0; i < m; i++ ) {
		cin >> begin >> end >> mid;

		for ( int j = 0; j < mid - begin; j++ ) {
			rotate(arr, begin, end);
		}
	}

	for ( int i = 1; i <= n; i++ ) {
		cout << arr[i] << ' ';
	}
	cout << endl;

    return 0;
}
