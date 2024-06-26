#include <cstdio>
#include <cassert>
#define __MAXSIZE__ 100002
#include "friend.h"
using namespace std;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}



// Confidence
int confidence[__MAXSIZE__];

// Host
int host[__MAXSIZE__];

// Protocol
int protocol[__MAXSIZE__];

// Main
int main(void)
{
	usaco();
	int n,i;

	// Number of people
	assert(scanf("%d",&n)==1);
	
	// Confidence
	for(i=0;i<n;i++)
		assert(scanf("%d",&confidence[i])==1);
	
	// Host and Protocol
	for(i=1;i<n;i++)
		assert(scanf("%d %d",&host[i],&protocol[i])==2);
	
	// Answer
	printf("%d\n",findSample(n,confidence,host,protocol));
	return 0;
}
