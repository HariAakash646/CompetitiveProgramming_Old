#include "tree.h"
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

std::vector<int> compute(int n, std::vector<int> F) {
	vi out;
	vi deg(n);
	forr(i, 1, n) {
		deg[F[i]]++;
	}
	priority_queue<int> pq;
	forr(i, 1, n) {
		if(!deg[i]) pq.push(i);
	}
	while(pq.size()) {
		int x = pq.top();
		pq.pop();
		if(!x) continue;
		out.pb(x);
		deg[F[x]]--;
		if(!deg[F[x]]) pq.push(F[x]);
	}
	return out;
}
