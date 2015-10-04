#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
#define A first
#define B second

class ApplesAndOrangesEasy {

public:

	static const int MAXN = 4e3;
	bool filled[MAXN];

	int maximumApples(int N, int K, vector <int> info) {

		int V = K / 2;

		memset(filled, 0, sizeof(filled));

		for(int i : info) {
			filled[i-1] = true;
		}

		int res = 0;
		for(int i = 0; i < N; i++) {
			if(!filled[i]) {
				int s = 0;
				for(int v = i - K; v < i; v++) {
					if(v >= 0) {
						s += filled[v];
					}
				}

				bool good = true;

				for(int l = i - K, r = i; l < i; l++, r++) {
					if(l >= 0) {
						s -= filled[l];
					}
					if(r < N) {
						s += filled[r];
					}
					if(s == V) good = false;
				}

				if(good) {
					filled[i] = true;
				}
			}

			if(filled[i]) {
				res++;
			}
		}

		return res;
	}
};

// vim:ft=cpp
