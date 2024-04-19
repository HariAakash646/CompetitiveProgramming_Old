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
    usaco();
    int n;
    scd(n);

    vi vec(n+1);
    frange(i, n) scd(vec[i]);

    int id = 0;
    lli tot = 0;
    frange(i, n) {
        if(vec[i] == 1) {
            if(id <= i) {
                forr(j, i+1, n+1) {
                    if(vec[j] != vec[j-1] + 1 && vec[j] != 1) {
                        id = j;
                        break;
                    }
                }
            }
            lli v = (id - i);
            tot += v * (v+1)/ 2;
        }
    }
    printf("%lld", tot);
}