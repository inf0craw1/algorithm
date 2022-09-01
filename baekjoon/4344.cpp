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

    int n, students, temp;
    
    cin >> n;
    cout << fixed;
    cout.precision(3);
    
    for ( int i = 0; i < n; i++ ) {
        vector<int> scores;
        double avg = 0;
        int count = 0;

        cin >> students;

        for ( int j = 0; j < students; j++ ) {
            cin >> temp;
            scores.push_back(temp);
            avg += temp;
        }
        avg /= students;
        for ( int j = 0; j < students; j++ ) {
            if ( scores[j] > avg) count++;
        }
        
        cout << count / double(students) * 100 << '%' << endl;
    }
    return 0;
}

