/* Algorithm:
Title meaning:
●There is a pile of beads from a necklace. The beads may appear repeatedly. Ask us if  we can connect them to form a necklace. The two beads in each section of the necklace must be satisfied. The first bead must be the same as the first one in the previous section. The two beads are the same, and the second bead in the last section must be

the same as the first in the first section. (That can form a ring)

●Ask whether it can be achieved, if one of the paths can be output

●Euler circuit:
If the in-degrees of the vertices in the connected graph are all even numbers, the Euler circuit exists

●The idea of seeking Euler circuit:
cyclically find the starting point. Start from a certain node, and then find a loop path from this point back to this point. This method ensures that every edge is traversed. If the edge of a certain point has not been traversed, let this point be the starting point and this edge as the starting edge, and connect it to the current ring. This way until all edges have been traversed. In this way, the entire graph is connected together.
Specific steps:
1.If there is no point connected to this point at this time, then add it to the path
2.If the point has connected points, then make a list and traverse these points until there are no connected points.
3.Process the current point, delete the side that has been passed, and perform the same operation on the adjacent point, and add the deleted point to the path.
4.This is actually a recursive process.*/


#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxM 1005
#define maxN 55
using namespace std;

const int n = 50;
int c[maxN][maxN], deg[maxN];
bool flag[maxN];

void initialize() {
    FOR (i, 1, n) {
        FOR (j, 1, n) c[i][j] = 0;
        deg[i] = 0;
        flag[i] = true;
    }
}

void dfs(int u) {
    flag[u] = false;
    FOR (v, 1, n)
        if (flag[v] && c[u][v]) dfs(v);
}

bool can_go_back(int x, int y) {
    Fill(flag, true);
    queue<int> Q;
    Q.push(y);
    flag[y] = false;
    c[x][y]--, c[y][x]--;
    bool stop = false;
    while (!Q.empty() && !stop) {
        int u = Q.front(); Q.pop();
        FOR (v, 1, n)
            if (flag[v] && c[u][v]) {
                flag[v] = false;
                if (v == x) {
                    stop = true;
                    break;
                }
                Q.push(v);
            }
    }
    c[x][y]++, c[y][x]++;
    return !flag[x];
}

bool solve() {
    FOR (i, 1, n)
        if (deg[i] % 2) return false;

    int s, f;
    FOR (i, 1, n)
        if (deg[i]) {
            s = i; break;
        }
    dfs(s);
    FOR (i, 1, n)
        if (deg[i] && flag[i]) return false;
        
    do {
        f = 0;
        FOR (v, 1, n)
            if (c[s][v]) {
                f = v;
                if (can_go_back(s, f)) break;
            }
        if (!f) break;
        printf("%d %d\n", s, f);
        c[s][f]--, c[f][s]--;
        s = f;
    } while (f);
    return true;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, m, u, v;
    scanf("%d", &Case);
    FOR (kk, 1, Case) {
        initialize();
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d", &u, &v);
            c[u][v]++, c[v][u]++;
            deg[u]++, deg[v]++;
        }

        printf("Case #%d\n", kk);
        if (!solve()) puts("some beads may be lost");
        if (kk < Case) putchar('\n');
    }
}
