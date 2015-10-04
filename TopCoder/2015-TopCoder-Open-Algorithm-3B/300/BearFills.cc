#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
#define A first
#define B second

class BearFills {

public:

	long long countSets(int N, long long W, long long H) {
		if(W > H) swap(W, H);
		assert(W <= H);
		ll res = 0;

		if((1ll << N) <= H) {
			return 0;
		}

		for(int i = N - 1; i >= 0; i--) {
			if((1ll << i) >= H) {
				res += (1ll << i);
			} else {
				// (1 << i)*2 >= H > (1 << i)
				assert((1ll << (i+1)) >= H);
				if((1ll << i) < W) break;
				H -= (1ll << i);
				if(H >= (1ll << i)) break;
				if(W > H) swap(W, H);
				assert(W <= H);
				assert(H <= (1ll << i));
			}
		}
		return res;
	}
};

// vim:ft=cpp
