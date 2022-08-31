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

    int temp, answer = 1;
    vector<int> remainder;

    for (int i = 0; i < 10; i++) {
        cin >> temp;
        remainder.push_back(temp % 42);
    }
    sort(remainder.begin(), remainder.end());
    for (int i = 1; i < 10; i++) {
        if (remainder[i - 1] != remainder[i]) {
            answer++;
        }
    }
    cout << answer << endl;
    return 0;
}

