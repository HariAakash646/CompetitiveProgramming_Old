#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

bool comp(pii x, pii y)
{
    if (x.first > y.first)
        return false;
    else if (x.first == y.first)
    {
        if (x.second > y.second)
            return false;
        else
            return true;
    }
    else
        return true;
}

int main()
{

    int n;
    while (true)
    {
        scd(n);
        if (n == 0)
            break;
        vi dp(n, 1);
        vii seq(n);
        frange(i, n)
        {
            scd(seq[i].first);
            scd(seq[i].second);
        }
        sort(seq.begin(), seq.end(), comp);

        forr(i, 1, n, 1)
        {

            int m = 0;
            frange(j, i)
            {
                if (seq[i].second >= seq[j].second)
                {
                    m = max(m, dp[j]);
                }
            }
            dp[i] = m + 1;
        }
        printf("%d\n", *max_element(dp.begin(), dp.end()));
    }
    printf("*");

    return 0;
}