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

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        seti st;
        frange(i, n) {
            int a;
            scd(a);
            st.insert(a);
        }

        if(st.size() == 1) {
            printf("Alice\n");
            continue;
        } 

        int c = 0;

        int pr = 0;
        auto it = st.begin();
        bool done = false;
        // while(it != prev(st.end())) {
        //     if(*it - pr > 1) done = true;
        //     else {
        //         c++;
        //     }
        //     pr = *it;
        //     it++;
        // }
        if(*st.begin() != 1) done = true;
        while(it != prev(st.end())) {
            if(*it - pr > 1) break;
            c++;
            pr = *it;
            it++;
        }
        // printf("%d ", c);
        if(done || c % 2 == 0) printf("Alice\n");
        else printf("Bob\n");
    }
}