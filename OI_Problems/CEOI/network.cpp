#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

vvi graph;
vi num, lowpt, pos, en, leav, par;
int timer = 1;

void dfs(int x) {
    num[x] = timer++;
    lowpt[x] = num[x];
    pos[num[x]] = x;
    int c = 0;

    for(auto e : graph[x]) {
        if(num[e]) {
            lowpt[x] = min(lowpt[x], lowpt[e]);
        }
        else {
            c++;
            dfs(e);
            lowpt[x] = min(lowpt[x], lowpt[e]);
            par[x] = e;
        }
    }
    en[x] = timer;
    if(!c) leav.pb(x);
}

int main() {
    // usaco();
    int n, m, r;
    scd(n);
    scd(m);
    scd(r);

    if(n == 1) {
        printf("1\n0");
        return 0;
    }

    graph = vvi(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
    }

    num = lowpt = en = pos = par = vi(n+1);
    dfs(r);

    forr(i, 1, n+1) {
        int x = pos[lowpt[i]];
        printf("%d ", en[x]-num[x]);
    }   
    printf("\n");
    lowpt[0] = -1;
    vii edg;

    // while(leav.size()) {
    //     int e = leav.back();
    //     leav.pop_back();
    //     int x = e;
    //     if(lowpt[e] != num[e]) {
    //         leav.pb(pos[lowpt[e]]);
    //         continue;
    //     }
    //     while(lowpt[e] == num[e]) {
    //         e = par[e];
    //     }
    //     if(!e) {
    //         edg.pb(mp(x, r));
    //     }
    //     else {
    //         edg.pb(mp(x, e));
    //         leav.pb(e);
    //     }
    // }
    // printf("%d\n", (int)edg.size());
    // for(auto p : edg) printf("%d %d\n", p.f, p.s);
}