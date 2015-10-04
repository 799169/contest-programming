#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
#define A first
#define B second

class ExactTree {

public:
	static const int MAXN = 60;
	static const int MAXM = 150;
	static const int MAXR = MAXM;

	ll N, M, R;
	ll dp[MAXN][MAXM];

	void insert(int n, ll val) {
		if(dp[n][val % M] == -1 || dp[n][val % M] > val) {
			dp[n][val % M] = val;
		}
	}

	ll go() {
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for(int i = 1; i <= N; i++) {
			for(int v = 0; v < M; v++) {
				if(dp[i - 1][v] == -1) continue;
				insert(i, dp[i - 1][v] + (N - i) * i);
			}
			if(i == N) break;
			for(int l = 1; l < i; l++) {
				int r = i - l;
				for(int a = 0; a < M; a++) {
					if(dp[l][a] == -1) continue;
					for(int b = 0; b < M; b++) {
						if(dp[r][b] == -1) continue;
						insert(i, dp[l][a] + dp[r][b]);
					}
				}
			}
		}
		return dp[N][R];
	}

	int getTree(int n, int m, int r) {
		N = n, M = m, R = r;
		return go();
	}
};

// vim:ft=cpp
