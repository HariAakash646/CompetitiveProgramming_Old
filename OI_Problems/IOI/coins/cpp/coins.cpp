#include "coins.h"
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

std::vector<int> coin_flips(std::vector<int> b, int c) {
    std::vector<int> flips(1);
    int v = 0;
    frange(i, 64) {
        if(b[i]) v = v ^ i;
    }
    flips[0] = c ^ v;
    return flips;
}

int find_coin(std::vector<int> b) {
    int v = 0;
    frange(i, 64) {
        if(b[i]) v = v ^ i;
    }
    return v;
}
