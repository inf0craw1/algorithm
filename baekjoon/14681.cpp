#include <bits/stdc++.h>

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

    int x, y;
    
    cin >> x >> y;

    if ( x > 0 && y > 0 ) {
        cout << 1 << endl;
        return 0;
    }
    if ( x > 0 && y < 0) {
        cout << 4 << endl;
        return 0;
    }
    if ( x < 0 && y > 0 ) {
        cout << 2 << endl;
        return 0;
    }
    if ( x < 0 && y < 0 ) {
        cout << 3 << endl;
        return 0;
    }
    return 0; 
}
