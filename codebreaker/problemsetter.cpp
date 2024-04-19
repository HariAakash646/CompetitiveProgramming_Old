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
    int c, p;
    scd(c);
    scd(p);
    vii vec(c);

    frange(i, c) {
        scd(vec[i].f);
        scd(vec[i].s);
    }
    sort(all(vec));

    vii prob(p);
    frange(i, p) {
        scd(prob[i].f);
        scd(prob[i].s);
    }
    sort(all(prob));

    int ma = 0;
    int id = 0;
    lli tot = 0;

    for(auto p : prob) {
        while(id < c && vec[id].f <= p.f) {
            ma = max(ma, vec[id].s);
            id++;
        }
        tot += max(0, ma - p.s);
    }
    printf("%lld", tot);
}