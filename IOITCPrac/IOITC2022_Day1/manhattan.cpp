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

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);

        vii vec(n);
        frange(i, n) {
            scd(vec[i].f);
            vec[i].s = i+1;
        }
        sort(all(vec));
        vi sub, ad;
        lli tot = 0;
        frange(i, n/2) {
            tot -= vec[i].f;
            sub.pb(vec[i].s);
        }
        forr(i, n/2, n) {
            tot += vec[i].f;
            ad.pb(vec[i].s);
        }

        printf("%lld\n", tot);
        frange(i, n/2) {
            printf("%d %d\n", sub[i], ad[i]);
        }
    }
}