#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define INF 0x7fffffff
#define LINF 0x7fffffffffffffff
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

/* - GLOBAL VARIABLES ---------------------------- */
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    int edge, vertex, startWith; cin >> edge >> vertex >> startWith;
    vector<vi> vertices = vector<vi>(edge+1, vi(0, 0));
    queue<int> q;
    int cnt = 1;
    vi visit = vi(edge + 1, 0);

    for ( int i = 0; i < vertex; i++ ) {
        int start, end; cin >> start >> end;

        vertices[start].push_back(end);
        vertices[end].push_back(start);
    }

    for ( int i = 1; i <= edge; i++ ) {
        sort(rall(vertices[i]));
    }

    q.push(startWith);

    while ( q.size() ) {
        ll cur = q.front();
        q.pop();

        if ( visit[cur] ) continue;
        visit[cur] = cnt++;

        for ( auto connectedEdge: vertices[cur] ) {
            if ( visit[connectedEdge] ) continue;
            q.push(connectedEdge);
        }

    }

    for ( int i = 1; i <= edge; i++ ) {
        cout << visit[i] << endl;
    }

    return 0;
}
