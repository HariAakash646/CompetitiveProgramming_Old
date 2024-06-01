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

struct Coord {
    int x, y, z;

    bool operator<(Coord &other) {
        return x + y + z < other.x + other.y + other.z;
    }
};


int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);
        
        vector<Coord> vec(n);

        frange(i, n) {
            scd(vec[i].x);
            scd(vec[i].y);
            scd(vec[i].z);
        }

        vll dp(1<<n);
        forr(i, 2, 1<<n) {
            if(__builtin_popcount(i) % 2 == 0) {
                frange(j, n) {
                    if(i & (1<<j)) {
                        int i1 = i ^ (1<<j);
                        frange(k, n) {
                            if(i1 & (1<<k)) {
                                auto p1 = vec[j];
                                auto p2 = vec[k];
                                int v = abs(p1.x-p2.x) + abs(p1.y-p2.y) + abs(p1.z-p2.z);
                                dp[i] = max(dp[i], dp[i1^(1<<k)] + v);
                            }
                        }
                    }
                } 
            }
        }
        printf("%lld\n", dp[(1<<n)-1]);
    }
}