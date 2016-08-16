#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e6;

int N;
ll X[MAXN];
ll P[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> X[i];
	}
	sort(X, X + N);

	P[0] = 0;
	for(int i = 0; i < N; i++) {
		P[i + 1] = P[i] + X[i];
	}

	int besti = -1, bestj = -1;
	ld res = -1;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= i && N - j > i; j++) {
			ld val = (P[i] - P[i - j]) + (P[N] - P[N - j]) + X[i];
			val /= 2 * j + 1;
			val -= X[i];
			if(res < val) {
				res = val;
				besti = i;
				bestj = j;
			}
		}
	}

	cout << 2 * bestj + 1 << '\n';
	for(int v = besti - bestj; v <= besti; v++) {
		cout << X[v] << ' ';
	}
	for(int v = N - bestj; v < N; v++) {
		cout << X[v] << ' ';
	}
	cout << '\n';

	return 0;
}
