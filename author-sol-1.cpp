#include <bits/stdc++.h>

using namespace std;

int CountPeak(vector<int> a) {
	int cnt = 0;
	for (int i = 1; i < (int) a.size() - 1; i++) {
		// count the extremum
		if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] <  a[i + 1])) {
			cnt++;
		}
	}
	return cnt;
}

void Solve(int& cnt, vector<int> a, int i = 0) {
	if (i == (int) a.size()) {
		cnt += CountPeak(a);
		return;
	}
	for (auto num : {0, 1, 2}) {
		a[i] = num;
		Solve(cnt, a, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int cnt = 0;
		// brute-force approach: produce all possible combinations/permutations of {0, 1, 2}
		Solve(cnt, a);
		cout << cnt << '\n';	
	}
	return 0;
}
