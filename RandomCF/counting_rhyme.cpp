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
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);

        vi vec(n+1);

        bool zer = false;

        frange(i, n) {
            int a;
            scd(a);
            vec[a]++;

            if(a == 1) zer = true;
        }

        

        vi cnt(n+1);

        forr(i, 1, n+1) {
            for(int j=i; j<=n; j+=i) {
                cnt[i] += vec[j];
            }
        }

        lli tot = n * (n-1)/2;

        vll dp(n+1);

        for(int i=n; i>=1; i--) {

            
            {
                lli c = 0;
                for(int j=i; j<=n; j+=i) c += cnt[j];
                dp[i] = c * (c-1)/2;
    
                for(int j=2*i; j<=n; j+=i) dp[i] -= dp[j];
                if(vec[i]) 
                    tot -= dp[i];
                printf("%d %lld\n", i, dp[i]);
            }
        }

        printf("%lld\n", tot);

    }
}