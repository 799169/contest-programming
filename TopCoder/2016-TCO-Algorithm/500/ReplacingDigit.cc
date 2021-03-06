#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

class ReplacingDigit {

public:

	int getMaximumStockWorth(vector <int> A, vector <int> D) {
		int p = 1;
		for(int i : A) {
			while(p <= i) p *= 10;
		}

		int res = 0;
		// p is greater than all of the A[i]

		int d = 9;
		for(p /= 10; p; p /= 10) {
			vector<int> cd;
			for(int i : A) {
				if(i >= p) cd.push_back((i / p) % 10);
			}
			sort(cd.begin(), cd.end());
			for(int i : cd) {
				while(d > 0 && D[d - 1] == 0) d--;
				if(d > i) {
					res += d * p;
					D[d - 1] --;
				} else {
					res += i * p;
				}
			}
		}
		return res;
	}
};

// vim:ft=cpp
