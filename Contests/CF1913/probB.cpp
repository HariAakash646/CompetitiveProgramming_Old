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
    fastio();
    int t;
    cin >> t;

    frange(_, t) {
        string str;
        cin >> str;

        int n = str.size();

        vi pref1(n+1), pref0(n+1);

        forr(i, 1, n+1) {
            pref1[i] = pref1[i-1];
            pref0[i] = pref0[i-1];
            if(str[i-1] == '1') pref1[i]++;
            else pref0[i]++;
        }
        if(pref0[n] > pref1[n]) swap(pref1, pref0);
        int nc = pref1[n];
        int out = 0;
        for(int i=0; i<=n; i++) {
            if(nc <= pref0[n-i]) {
                break;
            }
            else {
                out++;
                nc--;
            }
        }
        cout << out << "\n";
    }
}