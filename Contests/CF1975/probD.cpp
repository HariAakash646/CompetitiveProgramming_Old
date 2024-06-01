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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vvi graph;
vi depth;

void dfs(int x, int p) {
    for(auto e : graph[x]) {
        if(e != p) {
            depth[e] = depth[x]+1;
            dfs(e, x);
        }
    }
}

vi dfs2(int x, int p, int v) {
    if(x==v) {
        return {x};
    }
    for(auto e : graph[x]) {
        if(e != p) {
            vi out = dfs2(e, x, v);
            if(out.size()) {
                out.pb(x);
                return out;
            }
        }
    }
    return {};
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        int a, b;
        scd(a);
        scd(b);
        graph = vvi(n+1);

        frange(i, n-1) {
            int u, v;
            scd(u);
            scd(v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

        vi out = dfs2(a, 0, b);
        reverse(all(out));

        int sz = out.size();

        int v = out[(sz+1)/2-1];

        depth = vi(n+1);
        dfs(v, 0);

        int ma = *max_element(all(depth));

        printf("%d\n", 2*(n-1) - ma + sz/2);


    }
}