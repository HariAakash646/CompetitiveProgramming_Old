#include "Alice.h"
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

// you may define some global variables, but it does not work if you try to transfer any information from function Alice() to function Bob() through these variables.
// you had better not use the same global variables in function Alice() and in function Bob().

std::vector<std::pair<int,int>> Alice(){
	// add your code here
	
	// change below into your code
    long long x = setN(5000);
    vii out;
    lli v1 = (x-1)/5000 + 1;
    lli v2 = (x%5000+1);
    seti ev, ed;
    forr(i, 1, n+1) {
    	if(i%2) od.insert(i);
    	else ev.insert(i);
    }
    if(v1 == v2) {
    	if(v1%2) od.erase(v1);
    	else ev.erase(v1);
    	for(auto e : ev) out.pb(mp(v1, e));
    	for(auto e : od) out.pb(mp(v1, e));
    }
	else {
		if(v1%2) od.erase(v1);
		else ev.erase(v1);
		if(v2%2) od.erase(v2);
		else ev.erase(v2);
		for(auto e : ev) out.pb(mp(v1, e));
		for(auto e : od) out.pb(mp(v2, e));
	}
    return out;
}
