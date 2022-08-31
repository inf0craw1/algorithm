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

    int score;
    
    cin >> score;
    if (score >= 90) {
        cout << 'A' << endl;
        return 0;
    }
    if (score >= 80) {
        cout << 'B' << endl;
        return 0;
    }
    if (score >= 70) {
        cout << 'C' << endl;
        return 0;
    }
    if (score >= 60) {
        cout << 'D' << endl;
        return 0;
    }
    cout << 'F' << endl;
    return 0;
}

